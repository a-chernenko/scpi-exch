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

namespace scpi {
namespace source {
namespace level {
namespace detail {
CREATE_SUBSYSTEM_MNEMONIC(AMPLitude, CMnemonics::AMPLitude),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::AMPLitude),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::AMPLitude),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::AMPLitude),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::AMPLitude){};

CREATE_SUBSYSTEM_MNEMONIC(IMMediate, CMnemonics::IMMediate),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::IMMediate),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::IMMediate) {
  ADD_SUBSYSTEM_MNEMONIC(AMPLitude, IMMediate);
};

CREATE_SUBSYSTEM_MNEMONIC(LEVel, CMnemonics::LEVel),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::LEVel),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::LEVel),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::LEVel),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::LEVel) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(IMMediate, LEVel);
};
}  // namespace detail

template <std::size_t N, const const_string<N> &topsubsystem>
using mnemonics = detail::SUBSYSTEM_MNEMONIC_TYPE(LEVel)<N, topsubsystem>;
}  // namespace level
}  // namespace source
}  // namespace scpi
