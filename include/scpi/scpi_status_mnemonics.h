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
namespace status {
namespace detail {
CREATE_SUBSYSTEM_MNEMONIC(ENABle, CMnemonics::ENABle),
    ADD_SUBSYSTEM_COMMAND_MNEMONIC(CMnemonics::ENABle),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::ENABle){};

CREATE_SUBSYSTEM_MNEMONIC(CONDition, CMnemonics::CONDition),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::CONDition){};

CREATE_SUBSYSTEM_MNEMONIC(EVENT, CMnemonics::EVENT),
    ADD_SUBSYSTEM_QUERY_MNEMONIC(CMnemonics::EVENT){};

CREATE_SUBSYSTEM_MNEMONIC(TEMPerature, CMnemonics::TEMPerature) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, TEMPerature);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, TEMPerature);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, TEMPerature);
};

CREATE_SUBSYSTEM_MNEMONIC(TIMe, CMnemonics::TIMe) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, TIMe);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, TIMe);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, TIMe);
};

CREATE_SUBSYSTEM_MNEMONIC(FREQuency, CMnemonics::FREQuency) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, FREQuency);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, FREQuency);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, FREQuency);
};

CREATE_SUBSYSTEM_MNEMONIC(PHASe, CMnemonics::PHASe) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, PHASe);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, PHASe);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, PHASe);
};

CREATE_SUBSYSTEM_MNEMONIC(MODulation, CMnemonics::MODulation) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, MODulation);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, MODulation);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, MODulation);
};

CREATE_SUBSYSTEM_MNEMONIC(CALibration, CMnemonics::CALibration) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, CALibration);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, CALibration);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, CALibration);
};

CREATE_SUBSYSTEM_MNEMONIC(INTegrity, CMnemonics::INTegrity) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, INTegrity);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, INTegrity);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, INTegrity);
};

CREATE_SUBSYSTEM_MNEMONIC(VOLTage, CMnemonics::VOLTage) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, VOLTage);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, VOLTage);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, VOLTage);
};

CREATE_SUBSYSTEM_MNEMONIC(CURRent, CMnemonics::CURRent) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, CURRent);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, CURRent);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, CURRent);
};

CREATE_SUBSYSTEM_MNEMONIC(POWer, CMnemonics::POWer) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, POWer);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, POWer);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, POWer);
};

CREATE_SUBSYSTEM_MNEMONIC(OPERation, CMnemonics::OPERation) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, OPERation);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, OPERation);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, OPERation);
};

CREATE_SUBSYSTEM_MNEMONIC(QUEStionable, CMnemonics::QUEStionable) {
  ADD_SUBSYSTEM_MNEMONIC(ENABle, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(CONDition, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(EVENT, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(VOLTage, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(CURRent, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(TIMe, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(POWer, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(TEMPerature, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(FREQuency, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(PHASe, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(MODulation, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(CALibration, QUEStionable);
  ADD_SUBSYSTEM_MNEMONIC(INTegrity, QUEStionable);
};

CREATE_TOP_SUBSYSTEM_MNEMONIC(STATus, CMnemonics::STATus) {
  ADD_TOP_SUBSYSTEM_MNEMONIC(OPERation, STATus);
  ADD_TOP_SUBSYSTEM_MNEMONIC(QUEStionable, STATus);
};
}  // namespace detail

using mnemonics = detail::SUBSYSTEM_MNEMONIC_TYPE(STATus);
}  // namespace status
}  // namespace scpi
