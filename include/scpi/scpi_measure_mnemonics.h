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

#ifndef SCPI_MEASURE_MNEMONICS_H
#define SCPI_MEASURE_MNEMONICS_H

#include "scpi_mnemonics.h"

namespace ScpiMnemonics {
namespace Measure {
namespace Detail {
// 3.8 Measurement Function Layer
// 3.8.1 Simple Measurements
// 3.8.1.2 (SCPI-1999.0)
CREATE_SUBSYSTEM_MNEMONIC(AC, CMnemonics::AC),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::AC){};
// 3.8.1.3 (SCPI-1999.0)
CREATE_SUBSYSTEM_MNEMONIC(DC, CMnemonics::DC),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::DC){};
// 3.7 Fundamental Measurement Layer
// 3.7.2 (SCPI-1999.0)
CREATE_SUBSYSTEM_MNEMONIC(VOLTage, CMnemonics::VOLTage) {
  ADD_SUBSYSTEM_MNEMONIC(DC, VOLTage);
  ADD_SUBSYSTEM_MNEMONIC(AC, VOLTage);
};
// 3.7.3 (SCPI-1999.0)
CREATE_SUBSYSTEM_MNEMONIC(CURRent, CMnemonics::CURRent) {
  ADD_SUBSYSTEM_MNEMONIC(DC, CURRent);
  ADD_SUBSYSTEM_MNEMONIC(AC, CURRent);
};
// 3.7.4 (SCPI-1999.0)
CREATE_SUBSYSTEM_MNEMONIC(POWer, CMnemonics::POWer) {
  ADD_SUBSYSTEM_MNEMONIC(DC, POWer);
  ADD_SUBSYSTEM_MNEMONIC(AC, POWer);
};
// 3.7.7 (SCPI-1999.0)
CREATE_SUBSYSTEM_MNEMONIC(TEMPerature, CMnemonics::TEMPerature){

};
// 3.6 Presentation Layer
// 3.6.2 (SCPI-1999.0)
CREATE_SUBSYSTEM_MNEMONIC(SCALar, CMnemonics::SCALar) {
  ADD_SUBSYSTEM_MNEMONIC(CURRent, SCALar);
  ADD_SUBSYSTEM_MNEMONIC(POWer, SCALar);
  ADD_SUBSYSTEM_MNEMONIC(VOLTage, SCALar);
  ADD_SUBSYSTEM_MNEMONIC(TEMPerature, SCALar);
};
// 3. Measurement Instructions
// 3.1 (SCPI-1999.0)
CREATE_TOP_SUBSYSTEM_MNEMONIC(CONFigure, CMnemonics::CONFigure) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(SCALar, CONFigure);
};
// 3.2 (SCPI-1999.0)
CREATE_TOP_SUBSYSTEM_MNEMONIC(FETCh, CMnemonics::FETCh) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(SCALar, FETCh);
};
// 3.3 (SCPI-1999.0)
CREATE_TOP_SUBSYSTEM_MNEMONIC(READ, CMnemonics::READ) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(SCALar, READ);
};
// 3.4 (SCPI-1999.0)
CREATE_TOP_SUBSYSTEM_MNEMONIC(MEASure, CMnemonics::MEASure) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(SCALar, MEASure);
};

struct CMeasurementInstructionsMnemonics {
  static SUBSYSTEM_MNEMONIC_TYPE(CONFigure) CONFigure;
  static SUBSYSTEM_MNEMONIC_TYPE(FETCh) FETCh;
  static SUBSYSTEM_MNEMONIC_TYPE(READ) READ;
  static SUBSYSTEM_MNEMONIC_TYPE(MEASure) MEASure;
};
}  // namespace Detail

using Mnemonics = Detail::CMeasurementInstructionsMnemonics;
}  // namespace Measure
}  // namespace ScpiMnemonics

#endif  // SCPI_MEASURE_MNEMONICS_H
