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

using namespace Scpi;
using namespace ScpiMnemonics::Input;

CINPutSubsystem::CINPutSubsystem(const CScpiBase &scpi) :m_Scpi{scpi} {}

void CINPutSubsystem::SetImpedance(const double value,
                                   const ChannelType &channel) const {
  constexpr auto command = Mnemonics::IMPedance.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

double CINPutSubsystem::GetImpedance(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::IMPedance.QueryMnemonic;
  double value;
 m_Scpi.Query(query, channel, value);
  return value;
}

void CINPutSubsystem::SetAttenuation(const double value,
                                     const ChannelType &channel) const {
  constexpr auto command = Mnemonics::ATTenuation.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

double CINPutSubsystem::GetAttenuation(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::ATTenuation.QueryMnemonic;
  double value;
 m_Scpi.Query(query, channel, value);
  return value;
}

void CINPutSubsystem::SetAttenuationAuto(const bool enabled,
                                         const ChannelType &channel) const {
  constexpr auto command = Mnemonics::ATTenuation.AUTO.CommandMnemonic;
 m_Scpi.Command(command, channel, enabled);
}

bool CINPutSubsystem::GetAttenuationAuto(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::ATTenuation.AUTO.QueryMnemonic;
  bool value;
 m_Scpi.Query(query, channel, value);
  return value;
}
