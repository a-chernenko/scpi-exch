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

#ifndef SCPI_SOURCE_PROTECTION_MNEMONICS_H
#define SCPI_SOURCE_PROTECTION_MNEMONICS_H

#include "scpi_mnemonics.h"

namespace ScpiMnemonics {
namespace Source {
namespace Protection {
namespace Detail {
CREATE_SUBSYSTEM_MNEMONIC(LEVel, CMnemonics::LEVel),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::LEVel),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::LEVel),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::LEVel),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::LEVel){};

CREATE_SUBSYSTEM_MNEMONIC(CLEar, CMnemonics::CLEar){};

CREATE_SUBSYSTEM_MNEMONIC(TRIPped, CMnemonics::TRIPped),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::TRIPped){};

CREATE_SUBSYSTEM_MNEMONIC(STATe, CMnemonics::STATe),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::STATe),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::STATe){};

CREATE_SUBSYSTEM_MNEMONIC(PROTection, CMnemonics::PROTection) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(CLEar, PROTection);
  ADD_TOP_SUBSYSTEM_MNEMONIC(TRIPped, PROTection);
  ADD_TOP_SUBSYSTEM_MNEMONIC(STATe, PROTection);
  ADD_TOP_SUBSYSTEM_MNEMONIC(LEVel, PROTection);
};
}  // namespace Detail

template <std::size_t N, const const_string<N> &topsubsystem>
using Mnemonics = Detail::SUBSYSTEM_MNEMONIC_TYPE(PROTection)<N, topsubsystem>;
}  // namespace Protection
}  // namespace Source
}  // namespace ScpiMnemonics

#endif  // SCPI_SOURCE_PROTECTION_MNEMONICS_H
