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
namespace output {
namespace detail {
CREATE_SUBSYSTEM_MNEMONIC(STATe, CMnemonics::STATe),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::STATe),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::STATe){};

CREATE_TOP_SUBSYSTEM_MNEMONIC(OUTPut, CMnemonics::OUTPut) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(STATe, OUTPut);
};
}  // namespace detail

using mnemonics = detail::SUBSYSTEM_MNEMONIC_TYPE(OUTPut);
}  // namespace output
}  // namespace scpi
