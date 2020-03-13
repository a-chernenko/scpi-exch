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

#pragma once

#include "scpi_mnemonics.h"
#include "scpi_source_level_commands.h"
#include "scpi_source_protection_commands.h"
#include "scpi_units_type.h"

namespace scpi {
class SCPI_API POWerSubsystem {
 public:
  SOURcePROTectionCommands<sizeof(CMnemonics::POWer), CMnemonics::POWer,
                           power_units::type>
      PROTection;
  SOURceLEVelCommands<sizeof(CMnemonics::POWer), CMnemonics::POWer,
                      power_units::type>
      LEVel;

  POWerSubsystem() = delete;
  POWerSubsystem(const POWerSubsystem&) = delete;
  POWerSubsystem& operator=(const POWerSubsystem&) = delete;

 protected:
  POWerSubsystem(const scpi_base&);
  const scpi_base& _scpi;
};
}  // namespace scpi
