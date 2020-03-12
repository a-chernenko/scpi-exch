/*

   Copyright 2018 Alexander Chernenko (achernenko@mail.ru)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#include "ieee4882.h"
#include "hardware_exception.h"
#include "scpi_exception.h"

using std::string;
using namespace Ieee4882;
using namespace Hardware;
using namespace HardwareException;
using namespace Ieee4882Mnemonics;
using namespace Ieee4882RegistersType;
using namespace ScpiException;

CIeee4882::CIeee4882(const CHardware &scpiHardware)
    : m_Hardware(scpiHardware) {}

void CIeee4882::Command(const CommonCommandType &command) const {
  std::lock_guard<std::recursive_mutex> lock{m_Mutex};
  const string request = GetCommonCommandMnemonic(command);
  m_Hardware.WriteLine(request);
  ErrorHandler();
}

template <typename TypeValue>
void CIeee4882::Command(const CommonCommandType &command,
                        const TypeValue &value) const {
  std::lock_guard<std::recursive_mutex> lock{m_Mutex};
  const string request =
      GetCommonCommandMnemonic(command) + string{" "} + std::to_string(value);
  m_Hardware.WriteLine(request);
  ErrorHandler();
}

void CIeee4882::Query(
    const CommonQueryType &query, string &response,
    const unsigned int timeouts_mS = QueryTimeoutDefault_ms) const {
  std::lock_guard<std::recursive_mutex> lock{m_Mutex};
  const string request = GetCommonQueryMnemonic(query);
  m_Hardware.WriteLine(request);
  bool readTimeout{};
  try {
    m_Hardware.ReadLine(response, timeouts_mS);
  } catch (HardwareException::ReadTimeout) {
    readTimeout = true;
  }
  if (query != CommonQueryType::STB_ReadStatusByteQuery) ErrorHandler();
  if (readTimeout) throw HardwareException::ReadTimeout();
}

StatusByteRegisterType CIeee4882::GetStatusByteRegister() const {
  string response;
  Query(CommonQueryType::STB_ReadStatusByteQuery, response);
  return StatusByteRegisterType{response};
}

void CIeee4882::SetServiceRequestEnable(
    const StatusByteRegisterType &value) const {
  const auto reg = value.GetRegister();
  Command(CommonCommandType::SRE_ServiceRequestEnableCommand, reg);
}

StatusByteRegisterType CIeee4882::GetServiceRequestEnable() const {
  string response;
  Query(CommonQueryType::SRE_ServiceRequestEnableQuery, response);
  return StatusByteRegisterType{response};
}

void CIeee4882::SetEventStatusEnable(
    const EventStatusRegisterType &value) const {
  const auto reg = value.GetRegister();
  Command(CommonCommandType::ESE_StandardEventStatusEnableCommand, reg);
}

EventStatusRegisterType CIeee4882::GetEventStatusEnable() const {
  string response;
  Query(CommonQueryType::ESE_StandardEventStatusEnableQuery, response);
  return EventStatusRegisterType{response};
}

EventStatusRegisterType CIeee4882::GetEventStatusRegister() const {
  string response;
  Query(CommonQueryType::ESR_StandardEventStatusRegisterQuery, response);
  return EventStatusRegisterType{response};
}

int CIeee4882::SelfTest(string &message) const {
  string response;
  Query(CommonQueryType::TST_SelfTestQuery, response, SelfTestTimeout_ms);
  string::size_type offset{};
  auto result = std::stoi(response, &offset);
  if (result != 0) message = response.substr(offset);
  return result;
}

void CIeee4882::GetIdentification(string &idn) const {
  Query(CommonQueryType::IDN_IdentificationQuery, idn);
}

void CIeee4882::Reset() const { Command(CommonCommandType::RST_ResetCommand); }

void CIeee4882::WaitToContinue() const {
  Command(CommonCommandType::WAI_WaitToContinueCommand);
}

void CIeee4882::ClearStatus() const {
  Command(CommonCommandType::CLS_ClearStatusCommand);
}

void CIeee4882::SetOperationComplete() const {
  Command(CommonCommandType::OPC_OperationCompleteCommand);
}

void CIeee4882::WaitOperationComplete(const unsigned int timeouts_ms) const {
  string response;
  Query(CommonQueryType::OPCQ_OperationCompleteQuery, response, timeouts_ms);
}

void CIeee4882::ErrorHandler() const {
  if (!m_ErrorHandlerEnabled) return;
  const auto statusByte = GetStatusByteRegister();
  if (statusByte.Data.Bits.StandardEventStatusRegister) {
    const auto eventStatusRegister = GetEventStatusRegister();
    if (eventStatusRegister.Data.Bits.CommandError)
      throw CommandError();
    else if (eventStatusRegister.Data.Bits.QueryError)
      throw QueryError();
    else if (eventStatusRegister.Data.Bits.ExecutionError)
      throw ExecutionError();
    else if (eventStatusRegister.Data.Bits.DeviceDependentError)
      throw DeviceDependentError();
  }
}

bool CIeee4882::GetErrorHandlerEnabled() const noexcept {
  return m_ErrorHandlerEnabled;
}
void CIeee4882::SetErrorHandlerEnabled(const bool value) noexcept {
  m_ErrorHandlerEnabled = value;
}
