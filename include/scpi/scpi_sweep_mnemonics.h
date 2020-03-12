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

#ifndef SCPI_SWEEP_MNEMONICS_H
#define SCPI_SWEEP_MNEMONICS_H

#include "scpi_mnemonics.h"

namespace ScpiMnemonics {
namespace Sweep {
namespace Detail {
CREATE_SUBSYSTEM_MNEMONIC(COUNt, CMnemonics::COUNt),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::COUNt),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::COUNt){};

CREATE_SUBSYSTEM_MNEMONIC(STEP, CMnemonics::STEP),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::STEP),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::STEP){};

CREATE_SUBSYSTEM_MNEMONIC(POINts, CMnemonics::POINts),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::POINts),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::POINts){};

CREATE_SUBSYSTEM_MNEMONIC(AUTO, CMnemonics::AUTO),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::AUTO),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::AUTO){};

CREATE_SUBSYSTEM_MNEMONIC(TIME, CMnemonics::TIME),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::TIME),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::TIME) {
  ADD_SUBSYSTEM_MNEMONIC(AUTO, TIME);
};

CREATE_TOP_SUBSYSTEM_MNEMONIC(SWEep, CMnemonics::SWEep) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(POINts, SWEep);
  ADD_TOP_SUBSYSTEM_MNEMONIC(STEP, SWEep);
  ADD_TOP_SUBSYSTEM_MNEMONIC(COUNt, SWEep);
  ADD_TOP_SUBSYSTEM_MNEMONIC(TIME, SWEep);
};
}  // namespace Detail

using Mnemonics = Detail::SUBSYSTEM_MNEMONIC_TYPE(SWEep);
}  // namespace Sweep
}  // namespace ScpiMnemonics

#endif  // SCPI_SWEEP_MNEMONICS_H
