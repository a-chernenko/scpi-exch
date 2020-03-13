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

#ifndef SCPI_SOURCE_LEVEL_COMMANDS_HPP
#define SCPI_SOURCE_LEVEL_COMMANDS_HPP

#include "scpi_source_level_mnemonics.h"

namespace scpi {
template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
CSOURceLEVelCommands<N, topsubsystem, UnitsType>::CSOURceLEVelCommands(
    const scpi_base &scpi)
    :_scpi{scpi} {}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURceLEVelCommands<N, topsubsystem, UnitsType>::Set(
    const double level, const ChannelType &channel) const {
  constexpr auto command =
      ScpiMnemonics::Source::Level::Mnemonics<N, topsubsystem>::IMMediate
          .AMPLitude.CommandMnemonic;
 _scpi.Command(command, channel, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURceLEVelCommands<N, topsubsystem, UnitsType>::Set(
    const double level, const UnitsType &units) const {
  constexpr auto command =
      ScpiMnemonics::Source::Level::Mnemonics<N, topsubsystem>::IMMediate
          .AMPLitude.CommandMnemonic;
 _scpi.Command(command, units, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
double CSOURceLEVelCommands<N, topsubsystem, UnitsType>::Get(
    const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Source::Level::Mnemonics<N, topsubsystem>::IMMediate
          .AMPLitude.QueryMnemonic;
  double value;
 _scpi.Query(query, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
double CSOURceLEVelCommands<N, topsubsystem, UnitsType>::GetMaximum(
    const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Source::Level::Mnemonics<N, topsubsystem>::IMMediate
          .AMPLitude.QueryMaximumMnemonic;
  double value;
 _scpi.Query(query, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
double CSOURceLEVelCommands<N, topsubsystem, UnitsType>::GetMinimum(
    const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Source::Level::Mnemonics<N, topsubsystem>::IMMediate
          .AMPLitude.QueryMinimumMnemonic;
  double value;
 _scpi.Query(query, channel, value);
  return value;
}
}  // namespace Scpi

#endif  // SCPI_SOURCE_LEVEL_COMMANDS_HPP
