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

#ifndef IEEE4882_H
#define IEEE4882_H

#include <mutex>
#include "hardware.h"
#include "ieee4882_constants.h"
#include "ieee4882_mnemonics.h"
#include "ieee4882_registers_type.h"
#include "scpi_export.h"

namespace Ieee4882 {
class SCPI_API CIeee4882 final : private Ieee4882Mnemonics::CIeee4882Mnemonics,
                                 private CIeee4882Constants {
 public:
  CIeee4882(const Hardware::CHardware &);
  Ieee4882RegistersType::StatusByteRegisterType GetStatusByteRegister() const;
  void SetServiceRequestEnable(
      const Ieee4882RegistersType::StatusByteRegisterType &) const;
  Ieee4882RegistersType::StatusByteRegisterType GetServiceRequestEnable() const;
  void SetEventStatusEnable(
      const Ieee4882RegistersType::EventStatusRegisterType &) const;
  Ieee4882RegistersType::EventStatusRegisterType GetEventStatusEnable() const;
  Ieee4882RegistersType::EventStatusRegisterType GetEventStatusRegister() const;
  int SelfTest(std::string &) const;
  void GetIdentification(std::string &) const;
  void Reset() const;
  void WaitToContinue() const;
  void ClearStatus() const;
  void SetOperationComplete() const;
  void WaitOperationComplete(
      const unsigned int timeouts_ms = QueryTimeoutDefault_ms) const;
  void ErrorHandler() const;
  bool GetErrorHandlerEnabled() const noexcept;
  void SetErrorHandlerEnabled(const bool value = true) noexcept;

  CIeee4882() = delete;
  CIeee4882(const CIeee4882 &) = delete;
  CIeee4882 &operator=(const CIeee4882 &) = delete;

 private:
  mutable std::recursive_mutex m_Mutex;
  bool m_ErrorHandlerEnabled{};
  const Hardware::CHardware &m_Hardware;
  void Command(const Ieee4882Mnemonics::CommonCommandType &) const;
  template <typename TypeValue>
  void Command(const Ieee4882Mnemonics::CommonCommandType &,
               const TypeValue &) const;
  void Query(const Ieee4882Mnemonics::CommonQueryType &, std::string &,
             const unsigned int) const;
};
}  // namespace Ieee4882

#endif  // IEEE4882_H
