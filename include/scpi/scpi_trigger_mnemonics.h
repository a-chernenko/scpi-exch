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
namespace trigger {
namespace detail {
CREATE_TOP_SUBSYSTEM_MNEMONIC(ABORt, CMnemonics::ABORt){};

CREATE_TOP_SUBSYSTEM_MNEMONIC(INITiate, CMnemonics::INITiate){};

CREATE_SUBSYSTEM_MNEMONIC(SLOPe, CMnemonics::SLOPe){};

CREATE_SUBSYSTEM_MNEMONIC(SEQuence, CMnemonics::SEQuence) {
  ADD_SUBSYSTEM_MNEMONIC(SLOPe, SEQuence);
};

CREATE_TOP_SUBSYSTEM_MNEMONIC(TRIGger, CMnemonics::TRIGger) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(SEQuence, TRIGger);
};

struct TriggeringCommandsMnemonics {
  static SUBSYSTEM_MNEMONIC_TYPE(ABORt) ABORt;
  static SUBSYSTEM_MNEMONIC_TYPE(INITiate) INITiate;
  static SUBSYSTEM_MNEMONIC_TYPE(TRIGger) TRIGger;
};
}  // namespace detail

using mnemonics = detail::TriggeringCommandsMnemonics;
}  // namespace trigger
}  // namespace scpi
