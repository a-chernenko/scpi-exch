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
namespace frequency {
namespace detail {
CREATE_SUBSYSTEM_MNEMONIC(STARt, CMnemonics::STARt),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::STARt),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::STARt),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::STARt),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::STARt){};

CREATE_SUBSYSTEM_MNEMONIC(STOP, CMnemonics::STOP),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::STOP),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::STOP),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::STOP),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::STOP){};

CREATE_SUBSYSTEM_MNEMONIC(SPAN, CMnemonics::SPAN),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::SPAN),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::SPAN),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::SPAN),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::SPAN){};

CREATE_SUBSYSTEM_MNEMONIC(CENTer, CMnemonics::CENTer),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::CENTer),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::CENTer),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::CENTer),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::CENTer){};

CREATE_SUBSYSTEM_MNEMONIC(OFFSet, CMnemonics::OFFSet),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::OFFSet),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::OFFSet),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::OFFSet),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::OFFSet){};

CREATE_SUBSYSTEM_MNEMONIC(FIXed, CMnemonics::FIXed),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::FIXed),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::FIXed),
    ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(CMnemonics::FIXed),
    ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(CMnemonics::FIXed){};

CREATE_TOP_SUBSYSTEM_MNEMONIC(FREQuency, CMnemonics::FREQuency) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(STARt, FREQuency);
  ADD_TOP_SUBSYSTEM_MNEMONIC(STOP, FREQuency);
  ADD_TOP_SUBSYSTEM_MNEMONIC(SPAN, FREQuency);
  ADD_TOP_SUBSYSTEM_MNEMONIC(CENTer, FREQuency);
  ADD_TOP_SUBSYSTEM_MNEMONIC(OFFSet, FREQuency);
  ADD_TOP_SUBSYSTEM_MNEMONIC(FIXed, FREQuency);
};
}  // namespace detail

using mnemonics = detail::SUBSYSTEM_MNEMONIC_TYPE(FREQuency);
}  // namespace frequency
}  // namespace scpi
