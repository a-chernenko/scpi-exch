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

#ifndef SCPI_OUTPUT_SUBSYSTEM_H
#define SCPI_OUTPUT_SUBSYSTEM_H

#include "scpi_mnemonics.h"
#include "scpi_source_protection_commands.h"

namespace Scpi {
class SCPI_API COUTPutSubsystem {
 public:
  COUTPutSubsystem(const CScpiBase &);
  bool IsEnabled(const ChannelType &channel = {}) const;
  void SetEnabled(const bool, const ChannelType &channel = {}) const;
  CSOURcePROTectionCommands<sizeof(ScpiMnemonics::CMnemonics::OUTPut),
                            ScpiMnemonics::CMnemonics::OUTPut, UnitsTypeBase>
      m_PROTection;

  COUTPutSubsystem() = delete;
  COUTPutSubsystem(const COUTPutSubsystem &) = delete;
  COUTPutSubsystem &operator=(const COUTPutSubsystem &) = delete;

 private:
  const CScpiBase &m_Scpi;
};
}  // namespace Scpi

#endif  // SCPI_OUTPUT_SUBSYSTEM_H
