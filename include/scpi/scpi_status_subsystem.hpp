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
void CSTATusSubsystem::GetOPERationStatusEnable(
    register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::OPERation.ENABle.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::SetOPERationStatusEnable(
    const register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::OPERation.ENABle.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::GetOPERationStatusRegister(
    register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::OPERation.CONDition.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::GetOPERationStatusEvent(
    register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::OPERation.EVENT.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::GetQUEStionableStatusEnable(
    register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::QUEStionable.ENABle.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::SetQUEStionableStatusEnable(
    const register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::QUEStionable.ENABle.CommandMnemonic;
  _scpi.command(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::GetQUEStionableStatusRegister(
    register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::QUEStionable.CONDition.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::GetQUEStionableStatusEvent(
    register_type &value, const ChannelType &channel) const {
  constexpr auto mnemonic =
      mnemonics::Status::Mnemonics::QUEStionable.EVENT.QueryMnemonic;
  _scpi.query(mnemonic, channel, value);
}

template <typename register_type>
void CSTATusSubsystem::GetQUEStionableStatusEnable(
    const QUEStionableStatusType &type, register_type &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .VOLTage.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CURRent.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto mnemonic =
          mnemonics::Status::Mnemonics::QUEStionable.TIMe.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto mnemonic =
          mnemonics::Status::Mnemonics::QUEStionable.POWer.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .TEMPerature.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .FREQuency.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto mnemonic =
          mnemonics::Status::Mnemonics::QUEStionable.PHASe.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .MODulation.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CALibration.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .INTegrity.ENABle.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusEnable invalid argument");
  }
}

template <typename register_type>
void CSTATusSubsystem::SetQUEStionableStatusEnable(
    const QUEStionableStatusType &type, const register_type &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .VOLTage.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CURRent.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable.TIMe
                                    .ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable.POWer
                                    .ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .TEMPerature.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .FREQuency.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable.PHASe
                                    .ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .MODulation.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CALibration.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .INTegrity.ENABle.CommandMnemonic;
      _scpi.command(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "SetQUEStionableStatusEnable invalid argument");
  }
}

template <typename register_type>
void CSTATusSubsystem::GetQUEStionableStatusRegister(
    const QUEStionableStatusType &type, register_type &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .VOLTage.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CURRent.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable.TIMe
                                    .CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable.POWer
                                    .CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .TEMPerature.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .FREQuency.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable.PHASe
                                    .CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .MODulation.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CALibration.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .INTegrity.CONDition.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusRegister invalid argument");
  }
}

template <typename register_type>
void CSTATusSubsystem::GetQUEStionableStatusEvent(
    const QUEStionableStatusType &type, register_type &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .VOLTage.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CURRent.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto mnemonic =
          mnemonics::Status::Mnemonics::QUEStionable.TIMe.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto mnemonic =
          mnemonics::Status::Mnemonics::QUEStionable.POWer.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .TEMPerature.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .FREQuency.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto mnemonic =
          mnemonics::Status::Mnemonics::QUEStionable.PHASe.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .MODulation.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .CALibration.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto mnemonic = mnemonics::Status::Mnemonics::QUEStionable
                                    .INTegrity.EVENT.QueryMnemonic;
      _scpi.query(mnemonic, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusEvent invalid argument");
  }
}
}  // namespace scpi
