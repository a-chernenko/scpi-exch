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
using namespace mnemonics::Input;

CINPutSubsystem::CINPutSubsystem(const scpi_base &scpi) :_scpi{scpi} {}

void CINPutSubsystem::SetImpedance(const double value,
                                   const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::IMPedance.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CINPutSubsystem::GetImpedance(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::IMPedance.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CINPutSubsystem::SetAttenuation(const double value,
                                     const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::ATTenuation.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CINPutSubsystem::GetAttenuation(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::ATTenuation.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CINPutSubsystem::SetAttenuationAuto(const bool enabled,
                                         const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::ATTenuation.AUTO.CommandMnemonic;
 _scpi.command(mnemonic, channel, enabled);
}

bool CINPutSubsystem::GetAttenuationAuto(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::ATTenuation.AUTO.QueryMnemonic;
  bool value;
 _scpi.query(mnemonic, channel, value);
  return value;
}
