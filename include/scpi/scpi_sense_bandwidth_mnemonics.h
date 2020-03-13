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

namespace scpi::mnemonics {
namespace Sense {
namespace Bandwidth {
namespace detail {
CREATE_SUBSYSTEM_MNEMONIC(AUTO, CMnemonics::AUTO),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::AUTO),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::AUTO){};

CREATE_SUBSYSTEM_MNEMONIC(RESolution, CMnemonics::RESolution),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::RESolution),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::RESolution) {
  ADD_SUBSYSTEM_MNEMONIC(AUTO, RESolution);
};

CREATE_SUBSYSTEM_MNEMONIC(VIDeo, CMnemonics::VIDeo),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::VIDeo),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::VIDeo) {
  ADD_SUBSYSTEM_MNEMONIC(AUTO, VIDeo);
};

CREATE_TOP_SUBSYSTEM_MNEMONIC(BANDwidth, CMnemonics::BANDwidth) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(RESolution, BANDwidth);
  ADD_TOP_SUBSYSTEM_MNEMONIC(VIDeo, BANDwidth);
};
}  // namespace detail

using Mnemonics = detail::SUBSYSTEM_MNEMONIC_TYPE(BANDwidth);
}  // namespace Bandwidth
}  // namespace Sense
}  // namespace scpi::mnemonics
