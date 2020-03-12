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

#ifndef SCPI_STATUS_SUBSYSTEM_HPP
#define SCPI_STATUS_SUBSYSTEM_HPP

#include <stdexcept>
#include "scpi_status_mnemonics.h"

namespace Scpi {
template <typename RegisterType>
void CSTATusSubsystem::GetOPERationStatusEnable(
    RegisterType &value, const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Status::Mnemonics::OPERation.ENABle.QueryMnemonic;
 m_Scpi.Query(query, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::SetOPERationStatusEnable(
    const RegisterType &value, const ChannelType &channel) const {
  constexpr auto command =
      ScpiMnemonics::Status::Mnemonics::OPERation.ENABle.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::GetOPERationStatusRegister(
    RegisterType &value, const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Status::Mnemonics::OPERation.CONDition.QueryMnemonic;
 m_Scpi.Query(query, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::GetOPERationStatusEvent(
    RegisterType &value, const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Status::Mnemonics::OPERation.EVENT.QueryMnemonic;
 m_Scpi.Query(query, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::GetQUEStionableStatusEnable(
    RegisterType &value, const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Status::Mnemonics::QUEStionable.ENABle.QueryMnemonic;
 m_Scpi.Query(query, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::SetQUEStionableStatusEnable(
    const RegisterType &value, const ChannelType &channel) const {
  constexpr auto command =
      ScpiMnemonics::Status::Mnemonics::QUEStionable.ENABle.CommandMnemonic;
 m_Scpi.Command(command, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::GetQUEStionableStatusRegister(
    RegisterType &value, const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Status::Mnemonics::QUEStionable.CONDition.QueryMnemonic;
 m_Scpi.Query(query, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::GetQUEStionableStatusEvent(
    RegisterType &value, const ChannelType &channel) const {
  constexpr auto query =
      ScpiMnemonics::Status::Mnemonics::QUEStionable.EVENT.QueryMnemonic;
 m_Scpi.Query(query, channel, value);
}

template <typename RegisterType>
void CSTATusSubsystem::GetQUEStionableStatusEnable(
    const QUEStionableStatusType &type, RegisterType &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .VOLTage.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .CURRent.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable.TIMe
                                 .ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .POWer.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .TEMPerature.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .FREQuency.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .PHASe.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .MODulation.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .CALibration.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .INTegrity.ENABle.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusEnable invalid argument");
  }
}

template <typename RegisterType>
void CSTATusSubsystem::SetQUEStionableStatusEnable(
    const QUEStionableStatusType &type, const RegisterType &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .VOLTage.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .CURRent.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .TIMe.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .POWer.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .TEMPerature.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .FREQuency.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .PHASe.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .MODulation.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .CALibration.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto command = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                   .INTegrity.ENABle.CommandMnemonic;
     m_Scpi.Command(command, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "SetQUEStionableStatusEnable invalid argument");
  }
}

template <typename RegisterType>
void CSTATusSubsystem::GetQUEStionableStatusRegister(
    const QUEStionableStatusType &type, RegisterType &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .VOLTage.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .CURRent.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable.TIMe
                                 .CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .POWer.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .TEMPerature.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .FREQuency.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .PHASe.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .MODulation.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .CALibration.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .INTegrity.CONDition.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusRegister invalid argument");
  }
}

template <typename RegisterType>
void CSTATusSubsystem::GetQUEStionableStatusEvent(
    const QUEStionableStatusType &type, RegisterType &value,
    const ChannelType &channel) const {
  switch (type) {
    case QUEStionableStatusType::VOLTage: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .VOLTage.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::CURRent: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .CURRent.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::TIME: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable.TIMe
                                 .EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::POWer: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .POWer.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::TEMPerature: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .TEMPerature.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::FREQuency: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .FREQuency.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::PHASe: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .PHASe.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::MODulation: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .MODulation.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::CALibration: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .CALibration.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    case QUEStionableStatusType::INTegrity: {
      constexpr auto query = ScpiMnemonics::Status::Mnemonics::QUEStionable
                                 .INTegrity.EVENT.QueryMnemonic;
     m_Scpi.Query(query, channel, value);
      break;
    }
    default:
      throw std::invalid_argument(
          "GetQUEStionableStatusEvent invalid argument");
  }
}
}  // namespace Scpi

#endif  // SCPI_STATUS_SUBSYSTEM_HPP
