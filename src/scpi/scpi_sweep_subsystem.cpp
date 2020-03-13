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
using namespace sweep;

SWEepSubsystem::SWEepSubsystem(const scpi_base &scpi)
    : TIME{scpi}, _scpi{scpi} {}

void SWEepSubsystem::set_points(const double value,
                                const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::POINts.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double SWEepSubsystem::get_points(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::POINts.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void SWEepSubsystem::set_step(const double value,
                              const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STEP.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double SWEepSubsystem::get_step(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STEP.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void SWEepSubsystem::set_count(const double value,
                               const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::COUNt.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double SWEepSubsystem::get_count(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::COUNt.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

SWEepSubsystem::CTIME::CTIME(const scpi_base &scpi) : _scpi{scpi} {}

void SWEepSubsystem::CTIME::set(const double value,
                                const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::TIME.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double SWEepSubsystem::CTIME::get(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::TIME.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void SWEepSubsystem::CTIME::set_auto(const bool value,
                                     const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::TIME.AUTO.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

bool SWEepSubsystem::CTIME::get_auto(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::TIME.AUTO.QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
