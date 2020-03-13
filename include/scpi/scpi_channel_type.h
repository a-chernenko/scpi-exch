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

#include <string>

namespace scpi {
struct channel_type {
 public:
  explicit channel_type(unsigned int value) : value{value} {}
  channel_type() = default;
  channel_type(const channel_type &) = default;
  channel_type &operator=(const channel_type &) = default;
  channel_type(channel_type &&) = default;
  channel_type &operator=(channel_type &&) = default;

  friend bool operator!=(const channel_type &lhs, const unsigned int &rhs) {
    return (lhs.value != rhs);
  }
  friend bool operator>(const channel_type &lhs, const unsigned int &rhs) {
    return (lhs.value > rhs);
  }
  friend bool operator>(const unsigned int &lhs, const channel_type &rhs) {
    return (rhs.value > lhs);
  }
  friend bool operator<(const channel_type &lhs, const unsigned int &rhs) {
    return (lhs.value < rhs);
  }
  friend bool operator<(const unsigned int &lhs, const channel_type &rhs) {
    return (rhs.value < lhs);
  }
  channel_type operator++(int) {
    channel_type tmp(*this);
    operator++();
    return tmp;
  }
  channel_type &operator++() {
    ++value;
    return *this;
  }
  channel_type &operator=(const unsigned int &val) {
    value = val;
    return *this;
  }
  std::string to_string() const {
    std::string str = std::to_string(value);
    return str;
  }

 private:
  unsigned int value{};
};
}  // namespace scpi
