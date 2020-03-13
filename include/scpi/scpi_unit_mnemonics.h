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
namespace Unit {
namespace detail {
CREATE_SUBSYSTEM_MNEMONIC(VOLTage, CMnemonics::VOLTage),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::VOLTage),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::VOLTage){};

CREATE_SUBSYSTEM_MNEMONIC(CURRent, CMnemonics::CURRent),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::CURRent),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::CURRent){};

CREATE_SUBSYSTEM_MNEMONIC(POWer, CMnemonics::POWer),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::POWer),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::POWer){};

CREATE_TOP_SUBSYSTEM_MNEMONIC(UNIT, CMnemonics::UNIT) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(VOLTage, UNIT);
  ADD_TOP_SUBSYSTEM_MNEMONIC(CURRent, UNIT);
  ADD_TOP_SUBSYSTEM_MNEMONIC(POWer, UNIT);
};
}  // namespace detail

using Mnemonics = detail::SUBSYSTEM_MNEMONIC_TYPE(UNIT);
}  // namespace Unit
}  // namespace scpi::mnemonics
