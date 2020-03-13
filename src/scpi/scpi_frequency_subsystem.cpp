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
using namespace frequency;

FREQuencySubsystem::FREQuencySubsystem(const scpi_base &scpi) : _scpi{scpi} {}

void FREQuencySubsystem::set(const double value,
                             const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::FIXed.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

void FREQuencySubsystem::set(const double value,
                             const frequency_units::type &units) const {
  constexpr auto mnemonic = mnemonics::FIXed.CommandMnemonic;
  _scpi.command(mnemonic, units, value);
}

double FREQuencySubsystem::get(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::FIXed.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void FREQuencySubsystem::set_start(const double value,
                                   const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STARt.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double FREQuencySubsystem::get_start(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STARt.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void FREQuencySubsystem::set_stop(const double value,
                                  const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STOP.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double FREQuencySubsystem::get_stop(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::STOP.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void FREQuencySubsystem::set_center(const double value,
                                    const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::CENTer.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double FREQuencySubsystem::get_center(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::CENTer.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void FREQuencySubsystem::set_span(const double value,
                                  const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::SPAN.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double FREQuencySubsystem::get_span(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::SPAN.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

void FREQuencySubsystem::set_offset(const double value,
                                    const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::OFFSet.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

double FREQuencySubsystem::get_offset(const channel_type &channel) const {
  constexpr auto mnemonic = mnemonics::OFFSet.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
