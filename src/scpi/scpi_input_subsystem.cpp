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

#include "scpi_input_subsystem.h"
#include "scpi_input_mnemonics.h"

using namespace scpi;
using namespace input;

INPutSubsystem::INPutSubsystem(const scpi_base &scpi) : _scpi{scpi} {}

void INPutSubsystem::set_impedance(const double value,
                                   const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::IMPedance.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double INPutSubsystem::get_impedance(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::IMPedance.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void INPutSubsystem::set_attenuation(const double value,
                                     const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::ATTenuation.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double INPutSubsystem::get_attenuation(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::ATTenuation.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void INPutSubsystem::set_attenuation_auto(const bool enabled,
                                          const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::ATTenuation.AUTO.CommandMnemonic;
  _scpi.command(mnemonic, channel, enabled);
}

bool INPutSubsystem::get_attenuation_auto(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::ATTenuation.AUTO.QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
