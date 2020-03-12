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

#ifndef SCPI_SOURCE_PROTECTION_COMMANDS_HPP
#define SCPI_SOURCE_PROTECTION_COMMANDS_HPP

#include "scpi_source_protection_mnemonics.h"

namespace Scpi {
template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::
    CSOURcePROTectionCommands(const CScpiBase &scpi)
    :m_Scpi{scpi} {}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::Clear(
    const ChannelType &channel) const {
  constexpr auto command =
      ScpiMnemonics::Source::Protection::Mnemonics<N, topsubsystem>::CLEar
          .Mnemonic;
 m_Scpi.Command(command, channel);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
bool CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::IsTripped(
    const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Source::Protection::Mnemonics<N, topsubsystem>::TRIPped
          .QueryMnemonic;
  bool value;
 m_Scpi.Query(query, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::SetState(
    const bool enabled, const ChannelType &channel) const {
  constexpr auto command =
      ScpiMnemonics::Source::Protection::Mnemonics<N, topsubsystem>::STATe
          .CommandMnemonic;
 m_Scpi.Command(command, channel, enabled);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
bool CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::GetState(
    const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Source::Protection::Mnemonics<N, topsubsystem>::STATe
          .QueryMnemonic;
  bool value;
 m_Scpi.Query(query, channel, value);
  return value;
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::SetLevel(
    const double level, const ChannelType &channel) const {
  constexpr auto command =
      ScpiMnemonics::Source::Protection::Mnemonics<N, topsubsystem>::LEVel
          .CommandMnemonic;
 m_Scpi.Command(command, channel, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
void CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::SetLevel(
    const double level, const UnitsType &units) const {
  constexpr auto command =
      ScpiMnemonics::Source::Protection::Mnemonics<N, topsubsystem>::LEVel
          .CommandMnemonic;
 m_Scpi.Command(command, units, level);
}

template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
double CSOURcePROTectionCommands<N, topsubsystem, UnitsType>::GetLevel(
    const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Source::Protection::Mnemonics<N, topsubsystem>::LEVel
          .QueryMnemonic;
  double value;
 m_Scpi.Query(query, channel, value);
  return value;
}
}  // namespace Scpi

#endif  // SCPI_SOURCE_PROTECTION_COMMANDS_HPP
