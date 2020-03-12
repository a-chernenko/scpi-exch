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

#ifndef SCPI_POWER_SUBSYSTEM_H
#define SCPI_POWER_SUBSYSTEM_H

#include "scpi_mnemonics.h"
#include "scpi_source_level_commands.h"
#include "scpi_source_protection_commands.h"
#include "scpi_units_type.h"


namespace Scpi {
class SCPI_API CPOWerSubsystem {
 public:
  CSOURcePROTectionCommands<sizeof(ScpiMnemonics::CMnemonics::POWer),
                            ScpiMnemonics::CMnemonics::POWer,
                            PowerUnitsType::Type>
      m_PROTection;
  CSOURceLEVelCommands<sizeof(ScpiMnemonics::CMnemonics::POWer),
                       ScpiMnemonics::CMnemonics::POWer, PowerUnitsType::Type>
      m_LEVel;

  CPOWerSubsystem() = delete;
  CPOWerSubsystem(const CPOWerSubsystem&) = delete;
  CPOWerSubsystem& operator=(const CPOWerSubsystem&) = delete;

 protected:
  CPOWerSubsystem(const CScpiBase&);
  const CScpiBase &m_Scpi;
};
}  // namespace Scpi

#endif  // SCPI_POWER_SUBSYSTEM_H