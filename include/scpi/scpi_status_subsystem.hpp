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

#include <stdexcept>

#include "scpi_status_mnemonics.h"

namespace scpi {
template <typename register_type>
void STATusSubsystem::GetOPERationStatusEnable(
    register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic = status::mnemonics::OPERation.ENABle.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::SetOPERationStatusEnable(
    const register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic = status::mnemonics::OPERation.ENABle.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::GetOPERationStatusRegister(
    register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic =
      status::mnemonics::OPERation.CONDition.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::GetOPERationStatusEvent(
    register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic = status::mnemonics::OPERation.EVENT.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::GetQUEStionableStatusEnable(
    register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic =
      status::mnemonics::QUEStionable.ENABle.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::SetQUEStionableStatusEnable(
    const register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic =
      status::mnemonics::QUEStionable.ENABle.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::GetQUEStionableStatusRegister(
    register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic =
      status::mnemonics::QUEStionable.CONDition.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::GetQUEStionableStatusEvent(
    register_type &value, const channel_type &channel) const {
  constexpr auto mnemonic = status::mnemonics::QUEStionable.EVENT.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void STATusSubsystem::GetQUEStionableStatusEnable(
    const QUEStionableStatus &type, register_type &value,
    const channel_type &channel) const {
  switch (type) {
    case QUEStionableStatus::VOLTage: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.VOLTage.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CURRent: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CURRent.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TIME: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TIMe.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::POWer: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.POWer.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TEMPerature: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TEMPerature.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::FREQuency: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.FREQuency.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::PHASe: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.PHASe.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::MODulation: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.MODulation.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CALibration: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CALibration.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::INTegrity: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.INTegrity.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusEnable invalid argument");
  }
}

template <typename register_type>
void STATusSubsystem::SetQUEStionableStatusEnable(
    const QUEStionableStatus &type, const register_type &value,
    const channel_type &channel) const {
  switch (type) {
    case QUEStionableStatus::VOLTage: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.VOLTage.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CURRent: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CURRent.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TIME: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TIMe.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::POWer: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.POWer.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TEMPerature: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TEMPerature.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::FREQuency: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.FREQuency.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::PHASe: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.PHASe.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::MODulation: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.MODulation.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CALibration: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CALibration.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::INTegrity: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.INTegrity.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "SetQUEStionableStatusEnable invalid argument");
  }
}

template <typename register_type>
void STATusSubsystem::GetQUEStionableStatusRegister(
    const QUEStionableStatus &type, register_type &value,
    const channel_type &channel) const {
  switch (type) {
    case QUEStionableStatus::VOLTage: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.VOLTage.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CURRent: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CURRent.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TIME: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TIMe.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::POWer: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.POWer.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TEMPerature: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TEMPerature.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::FREQuency: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.FREQuency.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::PHASe: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.PHASe.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::MODulation: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.MODulation.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CALibration: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CALibration.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::INTegrity: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.INTegrity.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusRegister invalid argument");
  }
}

template <typename register_type>
void STATusSubsystem::GetQUEStionableStatusEvent(
    const QUEStionableStatus &type, register_type &value,
    const channel_type &channel) const {
  switch (type) {
    case QUEStionableStatus::VOLTage: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.VOLTage.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CURRent: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CURRent.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TIME: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TIMe.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::POWer: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.POWer.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::TEMPerature: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.TEMPerature.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::FREQuency: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.FREQuency.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::PHASe: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.PHASe.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::MODulation: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.MODulation.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::CALibration: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.CALibration.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatus::INTegrity: {
      constexpr auto mnemonic =
          status::mnemonics::QUEStionable.INTegrity.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusEvent invalid argument");
  }
}
}  // namespace scpi
