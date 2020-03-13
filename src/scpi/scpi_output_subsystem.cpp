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

#include "scpi_output_subsystem.h"
#include "scpi_output_mnemonics.h"

using namespace scpi;
using namespace output;

OUTPutSubsystem::OUTPutSubsystem(const scpi_base &scpi)
    : PROTection{scpi}, _scpi{scpi} {}

bool OUTPutSubsystem::is_enabled(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STATe.QueryMnemonic;
  bool enabled;
  _scpi.query(mnemonic, channel, enabled);
  return enabled;
}

void OUTPutSubsystem::set_enabled(const bool enabled,
                                  const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STATe.CommandMnemonic;
  _scpi.command(mnemonic, channel, enabled);
}
