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

#include "scpi_system_subsystem.h"
#include "scpi_system_mnemonics.h"

using std::string;
using namespace Scpi;
using namespace ScpiMnemonics::System;

CSYSTemSubsystem::CSYSTemSubsystem(const CScpiBase &scpi)
    : m_ERRor{scpi}, m_LOCK{scpi}, m_Scpi{scpi} {}

CSYSTemSubsystem::CERRor::CERRor(const CScpiBase &scpi) :m_Scpi{scpi} {}

CSYSTemSubsystem::LOCK::LOCK(const CScpiBase &scpi) :m_Scpi{scpi} {}

void CSYSTemSubsystem::CERRor::GetNext(int &errorCode,
                                       string &errorMessage) const {
  constexpr auto query = Mnemonics::ERRor.QueryMnemonic;
  string message;
 m_Scpi.Query(query, message);
  string::size_type index{};
  errorCode = std::stoi(message, &index);
  errorMessage = message.substr(++index);
  CScpiBase::RemoveQuotesInString(errorMessage);
}

int CSYSTemSubsystem::CERRor::GetCount() const {
  constexpr auto query = Mnemonics::ERRor.COUNt.QueryMnemonic;
  int value;
 m_Scpi.Query(query, value);
  return value;
}

void CSYSTemSubsystem::LOCK::Lock() const {
  constexpr auto command = Mnemonics::LOCK.Mnemonic;
 m_Scpi.Command(command);
}

void CSYSTemSubsystem::LOCK::Release() const {
  constexpr auto command = Mnemonics::LOCK.RELease.Mnemonic;
 m_Scpi.Command(command);
}
