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

#include "io_error.h"

namespace scpi {
void scpi_base::open(const std::string &ip,
                     const unsigned short port = port_default) {
  io.open(ip, port);
}

bool scpi_base::is_opened() const noexcept { return io.is_opened(); }

void scpi_base::close() { io.close(); }

template <size_t N, typename... ValueTypes>
void scpi_base::command_base(const const_string<N> &mnemonic,
                             const ValueTypes &... values) const {
  command_base(mnemonic.to_string(), values...);
}

template <typename... ValueTypes>
void scpi_base::command_base(const std::string &mnemonic,
                             const ValueTypes &... values) const {
  std::lock_guard<std::mutex> lock{_mutex};
  const char separator{','};
  std::stringstream request;
  request << mnemonic;
  make_separated_string(request, separator, values...);
  io.write(request.str());
  ieee488_io.error_handler();
}

template <size_t N, typename... ValueTypes>
void scpi_base::query_base(const const_string<N> &query,
                           ValueTypes &... values) const {
  query_base(query.to_string(), values...);
}

template <typename... ValueTypes>
void scpi_base::query_base(const std::string &query,
                           ValueTypes &... values) const {
  std::lock_guard<std::mutex> lock{_mutex};
  io.write(query);
  bool read_timeout{};
  std::string response;
  try {
    auto timeout_ms = get_query_timeout();
    io.read(response, timeout_ms);
  } catch (scpi::read_timeout) {
    read_timeout = true;
  }
  ieee488_io.error_handler();
  if (read_timeout) throw scpi::read_timeout();
  remove_quotes(response);
  std::stringstream ss;
  ss << response;
  parse_separated_string(ss, values...);
}

template <size_t N, typename... ValueTypes>
typename std::enable_if<!any_base_of<units_type_base, ValueTypes...>::value &&
                        !any_base_of<channel_type, ValueTypes...>::value>::type
scpi_base::command(const const_string<N> &mnemonic,
                   const ValueTypes &... values) const {
  command_base(mnemonic.to_string(), values...);
}

template <typename... ValueTypes>
typename std::enable_if<!any_base_of<units_type_base, ValueTypes...>::value &&
                        !any_base_of<channel_type, ValueTypes...>::value>::type
scpi_base::command(const std::string &mnemonic,
                   const ValueTypes &... values) const {
  command_base(mnemonic, values...);
}

template <size_t N, typename... ValueTypes>
void scpi_base::command(const const_string<N> &mnemonic,
                        const channel_type &channel,
                        const ValueTypes &... values) const {
  command(mnemonic.to_string(), channel, values...);
}

template <typename... ValueTypes>
void scpi_base::command(const std::string &mnemonic,
                        const channel_type &channel,
                        const ValueTypes &... values) const {
  if (channel > 0) {
    std::string channel_string;
    add_channel(channel_string, channel);
    command_base(mnemonic, values..., channel_string);
  } else
    command_base(mnemonic, values...);
}

template <size_t N, typename ValueType>
void scpi_base::command(const const_string<N> &mnemonic,
                        const units_type_base &unit,
                        const ValueType &value) const {
  command(mnemonic.to_string(), unit, value);
}

template <typename ValueType>
void scpi_base::command(const std::string &mnemonic,
                        const units_type_base &unit,
                        const ValueType &value) const {
  std::string mnemonic_string{mnemonic};
  mnemonic_string += std::to_string(value);
  mnemonic_string += unit.to_string();
  command_base(mnemonic_string);
}

template <size_t N>
void scpi_base::command(const const_string<N> &mnemonic,
                        const units_type_base &unit) const {
  command(mnemonic.to_string(), unit);
}

template <size_t N>
void scpi_base::command(const const_string<N> &mnemonic) const {
  command(mnemonic.to_string());
}

template <size_t N, typename... ValueTypes>
typename std::enable_if<!any_base_of<channel_type, ValueTypes...>::value>::type
scpi_base::query(const const_string<N> &mnemonic,
                 ValueTypes &... values) const {
  query_base(mnemonic.to_string(), values...);
}

template <typename... ValueTypes>
typename std::enable_if<!any_base_of<channel_type, ValueTypes...>::value>::type
scpi_base::query(const std::string &mnemonic, ValueTypes &... values) const {
  query_base(mnemonic, values...);
}

template <size_t N, typename... ValueTypes>
void scpi_base::query(const const_string<N> &mnemonic,
                      const channel_type &channel,
                      ValueTypes &... values) const {
  query(mnemonic.to_string(), channel, values...);
}

template <typename... ValueTypes>
void scpi_base::query(const std::string &mnemonic, const channel_type &channel,
                      ValueTypes &... values) const {
  if (channel > 0) {
    std::string mnemonic_string{mnemonic};
    add_channel(mnemonic_string, channel);
    query_base(mnemonic_string, values...);
  } else
    query_base(mnemonic, values...);
}

template <size_t N>
void scpi_base::query(const const_string<N> &mnemonic,
                      std::string &value) const {
  query(mnemonic.to_string(), value);
}

template <typename Arg, typename... Args>
void scpi_base::make_separated_string(std::stringstream &ss,
                                      const char separator, const Arg &arg,
                                      const Args &... args) const {
  ss << arg;
  auto args_num = sizeof...(args);
  if (args_num > 0) ss << separator;
  make_separated_string(ss, separator, args...);
}

template <typename Arg, typename... Args>
void scpi_base::parse_separated_string(std::stringstream &ss, Arg &arg,
                                       Args &... args) const {
  ss >> arg;
  auto args_num = sizeof...(args);
  if (args_num > 0) ss.ignore();  // skip separator
  parse_separated_string(ss, args...);
}
}  // namespace scpi
