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

using namespace scpi;
using namespace mnemonics::Sweep;

CSWEepSubsystem::CSWEepSubsystem(const scpi_base &scpi)
    : TIME{scpi}, _scpi{scpi} {}

void CSWEepSubsystem::SetPoints(const double value,
                                const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::POINts.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CSWEepSubsystem::GetPoints(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::POINts.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CSWEepSubsystem::SetStep(const double value,
                              const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::STEP.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CSWEepSubsystem::GetStep(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::STEP.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CSWEepSubsystem::SetCount(const double value,
                               const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::COUNt.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CSWEepSubsystem::GetGount(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::COUNt.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

CSWEepSubsystem::CTIME::CTIME(const scpi_base &scpi) :_scpi{scpi} {}

void CSWEepSubsystem::CTIME::Set(const double value,
                                 const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::TIME.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CSWEepSubsystem::CTIME::Get(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::TIME.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CSWEepSubsystem::CTIME::SetAuto(const bool value,
                                     const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::TIME.AUTO.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

bool CSWEepSubsystem::CTIME::GetAuto(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::TIME.AUTO.QueryMnemonic;
  bool value;
 _scpi.query(mnemonic, channel, value);
  return value;
}
