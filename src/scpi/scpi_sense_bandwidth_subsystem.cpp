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

#include "scpi_sense_bandwidth_subsystem.h"
#include "scpi_sense_bandwidth_mnemonics.h"

using namespace scpi;
using namespace mnemonics::Sense::Bandwidth;

CSENSeBANDwidthSubsystem::CSENSeBANDwidthSubsystem(const scpi_base &scpi)
    :_scpi{scpi} {}

void CSENSeBANDwidthSubsystem::SetResolution(const double value,
                                             const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::RESolution.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CSENSeBANDwidthSubsystem::GetResolution(
    const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::RESolution.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CSENSeBANDwidthSubsystem::SetResolutionAuto(
    const bool value, const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::RESolution.AUTO.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

bool CSENSeBANDwidthSubsystem::GetResolutionAuto(
    const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::RESolution.AUTO.QueryMnemonic;
  bool value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CSENSeBANDwidthSubsystem::SetVideo(const double value,
                                        const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::VIDeo.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

double CSENSeBANDwidthSubsystem::GetVideo(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::VIDeo.QueryMnemonic;
  double value;
 _scpi.query(mnemonic, channel, value);
  return value;
}

void CSENSeBANDwidthSubsystem::SetVideoAuto(const bool value,
                                            const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::VIDeo.AUTO.CommandMnemonic;
 _scpi.command(mnemonic, channel, value);
}

bool CSENSeBANDwidthSubsystem::GetVideoAuto(const ChannelType &channel) const {
  constexpr auto mnemonic = Mnemonics::VIDeo.AUTO.QueryMnemonic;
  bool value;
 _scpi.query(mnemonic, channel, value);
  return value;
}
