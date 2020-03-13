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

#include <algorithm>

#include "scpi.h"

using namespace scpi;

std::mutex scpi_base::_mutex;

scpi_base::~scpi_base() noexcept {
  if (is_opened()) try {
      close();
    } catch (...) {
    }
}

void scpi_base::set_query_timeout() noexcept {
  _query_timeout_ms = query_timeout_ms;
}

void scpi_base::set_query_timeout(const unsigned int timeout_ms) noexcept {
  _query_timeout_ms = timeout_ms;
}

unsigned int scpi_base::get_query_timeout() const noexcept {
  return _query_timeout_ms;
}

void scpi_base::split_separated_string(const std::string &unsplitted,
                                       const std::string &separator,
                                       std::vector<std::string> &splitted) {
  std::string::size_type start{};
  std::string::size_type index = unsplitted.find(separator);
  while (index != std::string::npos) {
    splitted.push_back(unsplitted.substr(start, index));
    index += separator.length();
    start += index;
    index = unsplitted.substr(start).find(separator);
  };
  splitted.push_back(unsplitted.substr(start));
}

void scpi_base::remove_char(std::string &str, const char char_to_remove) {
  auto begin = str.begin();
  auto end = str.end();
  auto is_equal = [=](const char ch) -> bool { return (ch == char_to_remove); };
  auto res = std::remove_if(begin, end, is_equal);
  str.resize(res - begin);
}

void scpi_base::remove_quotes(std::string &str) {
  const char double_quote_char{'\"'};
  remove_char(str, double_quote_char);
}

void scpi_base::remove_space(std::string &str) {
  const char space_char{' '};
  remove_char(str, space_char);
}

void scpi_base::add_channel(std::string &str, const channel_type &channel) {
  str += " (@";
  str += channel.to_string();
  str += ")";
}

void scpi_base::command(const std::string &command) const {
  std::lock_guard<std::mutex> lock(_mutex);
  io.write(command);
  ieee488_io.error_handler();
}

void scpi_base::command(const std::string &command,
                        const units_type_base &unit) const {
  command_base(command, unit.to_string());
}

void scpi_base::query(const std::string &query, std::string &value) const {
  std::lock_guard<std::mutex> lock(_mutex);
  io.write(query);
  bool read_timeout{};
  try {
    io.read(value, query_timeout_ms);
  } catch (scpi::read_timeout &) {
    read_timeout = true;
  }
  ieee488_io.error_handler();
  if (read_timeout) throw scpi::read_timeout();
}
