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
using namespace mnemonics::Measure;

CMEASureSubsystem::CMEASureSubsystem(const scpi_base &scpi) :_scpi{scpi} {}

double CMEASureSubsystem::Read(const unsigned int timeout_ms,
                               const ChannelType &channel) const {
  // auto query = Mnemonics::READ.SCALar.
  return 0;
}

double CMEASureSubsystem::CurrentDC(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::MEASure.SCALar.CURRent.DC.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

double CMEASureSubsystem::VoltageDC(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::MEASure.SCALar.VOLTage.DC.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

double CMEASureSubsystem::PowerDC(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::MEASure.SCALar.POWer.DC.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}
