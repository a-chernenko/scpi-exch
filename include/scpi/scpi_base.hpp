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

#ifndef SCPI_BASE_HPP
#define SCPI_BASE_HPP

#include "hardware_exception.h"

namespace Scpi {
void CScpiBase::Open(const std::string &ip,
                     const unsigned short port = PortDefault) {
  m_Hardware.Open(ip, port);
}

bool CScpiBase::IsOpened() const noexcept { return m_Hardware.IsOpened(); }

void CScpiBase::Close() { m_Hardware.Close(); }

template <size_t N, typename... ValueTypes>
void CScpiBase::CommandBase(const const_string<N> &command,
                            const ValueTypes &... values) const {
  CommandBase(command.to_string(), values...);
}

template <typename... ValueTypes>
void CScpiBase::CommandBase(const std::string &command,
                            const ValueTypes &... values) const {
  std::lock_guard<std::mutex> lock{m_Mutex};
  const char separator{','};
  std::stringstream request;
  request << command;
  MakeSeparatedString(request, separator, values...);
  m_Hardware.WriteLine(request.str());
  m_Ieee4882.ErrorHandler();
}

template <size_t N, typename... ValueTypes>
void CScpiBase::QueryBase(const const_string<N> &query,
                          ValueTypes &... values) const {
  QueryBase(query.to_string(), values...);
}

template <typename... ValueTypes>
void CScpiBase::QueryBase(const std::string &query,
                          ValueTypes &... values) const {
  std::lock_guard<std::mutex> lock{m_Mutex};
  m_Hardware.WriteLine(query);
  bool readTimeout{};
  std::string response;
  try {
    auto timeout_ms = GetQueryTimeout();
    m_Hardware.ReadLine(response, timeout_ms);
  } catch (HardwareException::ReadTimeout) {
    readTimeout = true;
  }
  m_Ieee4882.ErrorHandler();
  if (readTimeout) throw HardwareException::ReadTimeout();
  RemoveQuotesInString(response);
  std::stringstream ss;
  ss << response;
  ParseSeparatedString(ss, values...);
}

template <size_t N, typename... ValueTypes>
typename std::enable_if<!any_base_of<UnitsTypeBase, ValueTypes...>::value &&
                        !any_base_of<ChannelType, ValueTypes...>::value>::type
CScpiBase::Command(const const_string<N> &command,
                   const ValueTypes &... values) const {
  CommandBase(command.to_string(), values...);
}

template <typename... ValueTypes>
typename std::enable_if<!any_base_of<UnitsTypeBase, ValueTypes...>::value &&
                        !any_base_of<ChannelType, ValueTypes...>::value>::type
CScpiBase::Command(const std::string &command,
                   const ValueTypes &... values) const {
  CommandBase(command, values...);
}

template <size_t N, typename... ValueTypes>
void CScpiBase::Command(const const_string<N> &command,
                        const ChannelType &channel,
                        const ValueTypes &... values) const {
  Command(command.to_string(), channel, values...);
}

template <typename... ValueTypes>
void CScpiBase::Command(const std::string &command, const ChannelType &channel,
                        const ValueTypes &... values) const {
  if (channel > 0) {
    std::string channel_string;
    AddChannelToString(channel_string, channel);
    CommandBase(command, values..., channel_string);
  } else
    CommandBase(command, values...);
}

template <size_t N, typename ValueType>
void CScpiBase::Command(const const_string<N> &command,
                        const UnitsTypeBase &unit,
                        const ValueType &value) const {
  Command(command.to_string(), unit, value);
}

template <typename ValueType>
void CScpiBase::Command(const std::string &command, const UnitsTypeBase &unit,
                        const ValueType &value) const {
  std::string command_string{command};
  command_string += std::to_string(value);
  command_string += unit.to_string();
  CommandBase(command_string);
}

template <size_t N>
void CScpiBase::Command(const const_string<N> &command,
                        const UnitsTypeBase &unit) const {
  Command(command.to_string(), unit);
}

template <size_t N>
void CScpiBase::Command(const const_string<N> &command) const {
  Command(command.to_string());
}

template <size_t N, typename... ValueTypes>
typename std::enable_if<!any_base_of<ChannelType, ValueTypes...>::value>::type
CScpiBase::Query(const const_string<N> &query, ValueTypes &... values) const {
  QueryBase(query.to_string(), values...);
}

template <typename... ValueTypes>
typename std::enable_if<!any_base_of<ChannelType, ValueTypes...>::value>::type
CScpiBase::Query(const std::string &query, ValueTypes &... values) const {
  QueryBase(query, values...);
}

template <size_t N, typename... ValueTypes>
void CScpiBase::Query(const const_string<N> &query, const ChannelType &channel,
                      ValueTypes &... values) const {
  Query(query.to_string(), channel, values...);
}

template <typename... ValueTypes>
void CScpiBase::Query(const std::string &query, const ChannelType &channel,
                      ValueTypes &... values) const {
  if (channel > 0) {
    std::string query_string{query};
    AddChannelToString(query_string, channel);
    QueryBase(query_string, values...);
  } else
    QueryBase(query, values...);
}

template <size_t N>
void CScpiBase::Query(const const_string<N> &query, std::string &value) const {
  Query(query.to_string(), value);
}

template <typename Arg, typename... Args>
void CScpiBase::MakeSeparatedString(std::stringstream &ss, const char separator,
                                    const Arg &arg,
                                    const Args &... args) const {
  ss << arg;
  auto args_num = sizeof...(args);
  if (args_num > 0) ss << separator;
  MakeSeparatedString(ss, separator, args...);
}

template <typename Arg, typename... Args>
void CScpiBase::ParseSeparatedString(std::stringstream &ss, Arg &arg,
                                     Args &... args) const {
  ss >> arg;
  auto args_num = sizeof...(args);
  if (args_num > 0) ss.ignore();  // skip separator
  ParseSeparatedString(ss, args...);
}
}  // namespace Scpi

#endif  // SCPI_BASE_HPP