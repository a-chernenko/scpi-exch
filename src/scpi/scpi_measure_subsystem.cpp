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

#include "scpi_measure_subsystem.h"
#include "scpi_measure_mnemonics.h"

using namespace scpi;
using namespace measure;

MEASureSubsystem::MEASureSubsystem(const scpi_base &scpi) : _scpi{scpi} {}

double MEASureSubsystem::read(const unsigned int timeout_ms,
                              const channel_type &channel) const {
  // auto query = mnemonics::READ.SCALar.
  // FIXME:
  return 0;
}

double MEASureSubsystem::current_dc(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::MEASure.SCALar.CURRent.DC.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

double MEASureSubsystem::voltage_dc(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::MEASure.SCALar.VOLTage.DC.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

double MEASureSubsystem::power_dc(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::MEASure.SCALar.POWer.DC.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
