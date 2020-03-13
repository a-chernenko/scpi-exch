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
          typename UnitsType>
CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::
    CSOURcePROTectionCommands(const scpi_base &scpi)
    : _scpi{scpi} {}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::Clear(
    const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Source::Protection::Mnemonics<N, topsubsystem>::CLEar.Mnemonic;
  _scpi.command(mnemonic, channel);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
bool CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::IsTripped(
    const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Source::Protection::Mnemonics<N, topsubsystem>::TRIPped
          .QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::SetState(
    const bool enabled, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Source::Protection::Mnemonics<N, topsubsystem>::STATe
          .CommandMnemonic;
  _scpi.command(mnemonic, channel, enabled);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
bool CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::GetState(
    const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Source::Protection::Mnemonics<N, topsubsystem>::STATe
          .QueryMnemonic;
  bool value;
  _scpi.query(mnemonic, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::SetLevel(
    const double level, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Source::Protection::Mnemonics<N, topsubsystem>::LEVel
          .CommandMnemonic;
  _scpi.command(mnemonic, channel, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::SetLevel(
    const double level, const UnitsType &units) const {
  constexpr auto mnemonic =
      mnemonics::Source::Protection::Mnemonics<N, topsubsystem>::LEVel
          .CommandMnemonic;
  _scpi.command(mnemonic, units, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
double CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::GetLevel(
    const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Source::Protection::Mnemonics<N, topsubsystem>::LEVel
          .QueryMnemonic;
  double value;
  _scpi.query(mnemonic, channel, value);
  return value;
}
}  // namespace scpi
