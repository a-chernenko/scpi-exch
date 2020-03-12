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

#ifndef SCPI_TRIGGER_MNEMONICS_H
#define SCPI_TRIGGER_MNEMONICS_H

#include "scpi_mnemonics.h"

namespace ScpiMnemonics {
namespace Trigger {
namespace Detail {
CREATE_TOP_SUBSYSTEM_MNEMONIC(ABORt, CMnemonics::ABORt){};

CREATE_TOP_SUBSYSTEM_MNEMONIC(INITiate, CMnemonics::INITiate){};

CREATE_SUBSYSTEM_MNEMONIC(SLOPe, CMnemonics::SLOPe){};

CREATE_SUBSYSTEM_MNEMONIC(SEQuence, CMnemonics::SEQuence) {
  ADD_SUBSYSTEM_MNEMONIC(SLOPe, SEQuence);
};

CREATE_TOP_SUBSYSTEM_MNEMONIC(TRIGger, CMnemonics::TRIGger) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(SEQuence, TRIGger);
};

struct CTriggeringCommandsMnemonics {
  static SUBSYSTEM_MNEMONIC_TYPE(ABORt) ABORt;
  static SUBSYSTEM_MNEMONIC_TYPE(INITiate) INITiate;
  static SUBSYSTEM_MNEMONIC_TYPE(TRIGger) TRIGger;
};
}  // namespace Detail

using Mnemonics = Detail::CTriggeringCommandsMnemonics;
}  // namespace Trigger
}  // namespace ScpiMnemonics

#endif  // SCPI_TRIGGER_MNEMONICS_H
