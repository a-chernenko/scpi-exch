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
using namespace sense::bandwidth;

SENSeBANDwidthSubsystem::SENSeBANDwidthSubsystem(const scpi_base &scpi)
    : _scpi{scpi} {}

void SENSeBANDwidthSubsystem::set_resolution(
    const double value, const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::RESolution.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double SENSeBANDwidthSubsystem::get_resolution(
    const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::RESolution.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void SENSeBANDwidthSubsystem::set_resolution_auto(
    const bool value, const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::RESolution.AUTO.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

bool SENSeBANDwidthSubsystem::get_resolution_auto(
    const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::RESolution.AUTO.QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void SENSeBANDwidthSubsystem::set_video(const double value,
                                        const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::VIDeo.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double SENSeBANDwidthSubsystem::get_video(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::VIDeo.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void SENSeBANDwidthSubsystem::set_video_auto(
    const bool value, const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::VIDeo.AUTO.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

bool SENSeBANDwidthSubsystem::get_video_auto(
    const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::VIDeo.AUTO.QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
