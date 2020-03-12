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

#include "scpi_trigger_subsystem.h"
#include "scpi_trigger_mnemonics.h"

using std::string;
using namespace Scpi;
using namespace ScpiMnemonics::Trigger;

CTRIGgerSubsystem::CTRIGgerSubsystem(const CScpiBase &scpi) :m_Scpi{scpi} {}

void CTRIGgerSubsystem::Initiate() const {
  constexpr auto command = Mnemonics::INITiate.Mnemonic;
 m_Scpi.Command(command);
}

void CTRIGgerSubsystem::Abort() const {
  constexpr auto command = Mnemonics::ABORt.Mnemonic;
 m_Scpi.Command(command);
}
