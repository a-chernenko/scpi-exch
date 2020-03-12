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

#include "scpi_sweep_subsystem.h"
#include "scpi_sweep_mnemonics.h"

using namespace Scpi;
using namespace ScpiMnemonics::Sweep;

CSWEepSubsystem::CSWEepSubsystem(const CScpiBase &scpi)
    : m_TIME{scpi}, m_Scpi{scpi} {}

void CSWEepSubsystem::SetPoints(const double value,
                                const ChannelType &channel) const {
  constexpr auto command = Mnemonics::POINts.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

double CSWEepSubsystem::GetPoints(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::POINts.QueryMnemonic;
  double value;
 m_Scpi.Query(query, channel, value);
  return value;
}

void CSWEepSubsystem::SetStep(const double value,
                              const ChannelType &channel) const {
  constexpr auto command = Mnemonics::STEP.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

double CSWEepSubsystem::GetStep(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::STEP.QueryMnemonic;
  double value;
 m_Scpi.Query(query, channel, value);
  return value;
}

void CSWEepSubsystem::SetCount(const double value,
                               const ChannelType &channel) const {
  constexpr auto command = Mnemonics::COUNt.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

double CSWEepSubsystem::GetGount(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::COUNt.QueryMnemonic;
  double value;
 m_Scpi.Query(query, channel, value);
  return value;
}

CSWEepSubsystem::CTIME::CTIME(const CScpiBase &scpi) :m_Scpi{scpi} {}

void CSWEepSubsystem::CTIME::Set(const double value,
                                 const ChannelType &channel) const {
  constexpr auto command = Mnemonics::TIME.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

double CSWEepSubsystem::CTIME::Get(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::TIME.QueryMnemonic;
  double value;
 m_Scpi.Query(query, channel, value);
  return value;
}

void CSWEepSubsystem::CTIME::SetAuto(const bool value,
                                     const ChannelType &channel) const {
  constexpr auto command = Mnemonics::TIME.AUTO.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

bool CSWEepSubsystem::CTIME::GetAuto(const ChannelType &channel) const {
  constexpr auto query = Mnemonics::TIME.AUTO.QueryMnemonic;
  bool value;
 m_Scpi.Query(query, channel, value);
  return value;
}
