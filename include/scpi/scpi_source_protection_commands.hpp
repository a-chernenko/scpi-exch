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

#pragma once

#include "scpi_source_protection_mnemonics.h"

namespace scpi {
template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
SOURcePROTectionCommands<N, topsubsystem, units_type>::SOURcePROTectionCommands(
    const scpi_base &scpi)
    : _scpi{scpi} {}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
void SOURcePROTectionCommands<N, topsubsystem, units_type>::clear(
    const channel_type &channel) const {
  constexpr auto mnemonic =
      source::protection::mnemonics<N, topsubsystem>::CLEar.Mnemonic;
  _scpi.command(mnemonic, channel);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
bool SOURcePROTectionCommands<N, topsubsystem, units_type>::is_tripped(
    const channel_type &channel) const {
  constexpr auto mnemonic =
      source::protection::mnemonics<N, topsubsystem>::TRIPped.QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
void SOURcePROTectionCommands<N, topsubsystem, units_type>::set_state(
    const bool enabled, const channel_type &channel) const {
  constexpr auto mnemonic =
      source::protection::mnemonics<N, topsubsystem>::STATe.CommandMnemonic;
  _scpi.command(mnemonic, channel, enabled);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
bool SOURcePROTectionCommands<N, topsubsystem, units_type>::get_state(
    const channel_type &channel) const {
  constexpr auto mnemonic =
      source::protection::mnemonics<N, topsubsystem>::STATe.QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
void SOURcePROTectionCommands<N, topsubsystem, units_type>::set_level(
    const double level, const channel_type &channel) const {
  constexpr auto mnemonic =
      source::protection::mnemonics<N, topsubsystem>::LEVel.CommandMnemonic;
  _scpi.command(mnemonic, channel, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
void SOURcePROTectionCommands<N, topsubsystem, units_type>::set_level(
    const double level, const units_type &units) const {
  constexpr auto mnemonic =
      source::protection::mnemonics<N, topsubsystem>::LEVel.CommandMnemonic;
  _scpi.command(mnemonic, units, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
double SOURcePROTectionCommands<N, topsubsystem, units_type>::get_level(
    const channel_type &channel) const {
  constexpr auto mnemonic =
      source::protection::mnemonics<N, topsubsystem>::LEVel.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
}  // namespace scpi
