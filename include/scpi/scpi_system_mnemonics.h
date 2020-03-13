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
namespace System {
namespace detail {
CREATE_SUBSYSTEM_MNEMONIC(NEXT, CMnemonics::NEXT),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::NEXT){};

CREATE_SUBSYSTEM_MNEMONIC(RELease, CMnemonics::RELease){};

CREATE_SUBSYSTEM_MNEMONIC(LOCK, CMnemonics::LOCK) {
  ADD_SUBSYSTEM_MNEMONIC(RELease, LOCK);
};

CREATE_SUBSYSTEM_MNEMONIC(COUNt, CMnemonics::COUNt),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::COUNt){};

CREATE_SUBSYSTEM_MNEMONIC(ERRor, CMnemonics::ERRor),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::ERRor) {
  ADD_SUBSYSTEM_MNEMONIC(NEXT, ERRor);
  ADD_SUBSYSTEM_MNEMONIC(COUNt, ERRor);
};

CREATE_TOP_SUBSYSTEM_MNEMONIC(SYSTem, CMnemonics::SYSTem) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(ERRor, SYSTem);
  ADD_TOP_SUBSYSTEM_MNEMONIC(LOCK, SYSTem);
};
}  // namespace detail

using Mnemonics = detail::SUBSYSTEM_MNEMONIC_TYPE(SYSTem);
}  // namespace System
}  // namespace scpi::mnemonics
