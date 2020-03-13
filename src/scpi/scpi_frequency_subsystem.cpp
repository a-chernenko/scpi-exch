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

#include "scpi_frequency_subsystem.h"
#include "scpi_frequency_mnemonics.h"

using namespace scpi;
using namespace mnemonics::Frequency;

CFREQuencySubsystem::CFREQuencySubsystem(const scpi_base &scpi) : _scpi{scpi} {}

void CFREQuencySubsystem::Set(const double value,
                              const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::FIXed.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

void CFREQuencySubsystem::Set(const double value,
                              const FrequencyUnitsType::Type &units) const {
  constexpr auto mnemonic = Mnemonics::FIXed.CommandMnemonic;
  _scpi.command(mnemonic, units, value);
}

double CFREQuencySubsystem::Get(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::FIXed.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void CFREQuencySubsystem::SetStart(const double value,
                                   const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::STARt.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double CFREQuencySubsystem::GetStart(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::STARt.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void CFREQuencySubsystem::SetStop(const double value,
                                  const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::STOP.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double CFREQuencySubsystem::GetStop(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::STOP.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void CFREQuencySubsystem::SetCenter(const double value,
                                    const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::CENTer.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double CFREQuencySubsystem::GetCenter(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::CENTer.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void CFREQuencySubsystem::SetSpan(const double value,
                                  const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::SPAN.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double CFREQuencySubsystem::GetSpan(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::SPAN.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void CFREQuencySubsystem::SetOffset(const double value,
                                    const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::OFFSet.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double CFREQuencySubsystem::GetOffset(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::OFFSet.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
