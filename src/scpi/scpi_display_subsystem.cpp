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

#include "scpi_display_subsystem.h"
#include "scpi_display_mnemonics.h"

using namespace scpi;
using namespace ScpiMnemonics::Display;

CDISPlaySubsystem::CDISPlaySubsystem(const scpi_base &scpi) :_scpi{scpi} {}

void CDISPlaySubsystem::SetEnabled(const bool value) const {
  constexpr auto command = Mnemonics::ENABle.CommandMnemonic;
 _scpi.Command(command, value);
}

bool CDISPlaySubsystem::GetEnabled() const {
  constexpr auto query = Mnemonics::ENABle.QueryMnemonic;
  bool value;
 _scpi.Query(query, value);
  return value;
}
