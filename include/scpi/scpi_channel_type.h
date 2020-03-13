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

#ifndef SCPI_CHANNEL_TYPE_H
#define SCPI_CHANNEL_TYPE_H

#include <string>

namespace scpi {
struct ChannelType {
 public:
  explicit ChannelType(unsigned int value) : value{value} {}
  ChannelType() = default;
  ChannelType(const ChannelType &) = default;
  ChannelType &operator=(const ChannelType &) = default;
  ChannelType(ChannelType &&) = default;
  ChannelType &operator=(ChannelType &&) = default;

  friend bool operator!=(const ChannelType &lhs, const unsigned int &rhs) {
    return (lhs.value != rhs);
  }
  friend bool operator>(const ChannelType &lhs, const unsigned int &rhs) {
    return (lhs.value > rhs);
  }
  friend bool operator>(const unsigned int &lhs, const ChannelType &rhs) {
    return (rhs.value > lhs);
  }
  friend bool operator<(const ChannelType &lhs, const unsigned int &rhs) {
    return (lhs.value < rhs);
  }
  friend bool operator<(const unsigned int &lhs, const ChannelType &rhs) {
    return (rhs.value < lhs);
  }
  ChannelType operator++(int) {
    ChannelType tmp(*this);
    operator++();
    return tmp;
  }
  ChannelType &operator++() {
    ++value;
    return *this;
  }
  ChannelType &operator=(const unsigned int &val) {
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
}  // namespace Scpi

#endif  // SCPI_CHANNEL_TYPE_H
