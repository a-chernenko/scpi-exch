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

#include "scpi_source_level_mnemonics.h"

namespace scpi {
template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
SOURceLEVelCommands<N, topsubsystem, units_type>::SOURceLEVelCommands(
    const scpi_base &scpi)
    : _scpi{scpi} {}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
void SOURceLEVelCommands<N, topsubsystem, units_type>::set(
    const double level, const channel_type &channel) const {
  constexpr auto mnemonic = source::level::mnemonics<N, topsubsystem>::IMMediate
                                .AMPLitude.CommandMnemonic;
  _scpi.command(mnemonic, channel, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
void SOURceLEVelCommands<N, topsubsystem, units_type>::set(
    const double level, const units_type &units) const {
  constexpr auto mnemonic = source::level::mnemonics<N, topsubsystem>::IMMediate
                                .AMPLitude.CommandMnemonic;
  _scpi.command(mnemonic, units, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
double SOURceLEVelCommands<N, topsubsystem, units_type>::get(
    const channel_type &channel) const {
  constexpr auto mnemonic = source::level::mnemonics<N, topsubsystem>::IMMediate
                                .AMPLitude.QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
double SOURceLEVelCommands<N, topsubsystem, units_type>::get_maximum(
    const channel_type &channel) const {
  constexpr auto mnemonic = source::level::mnemonics<N, topsubsystem>::IMMediate
                                .AMPLitude.QueryMaximumMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename units_type>
double SOURceLEVelCommands<N, topsubsystem, units_type>::get_minimum(
    const channel_type &channel) const {
  constexpr auto mnemonic = source::level::mnemonics<N, topsubsystem>::IMMediate
                                .AMPLitude.QueryMinimumMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
}  // namespace scpi
