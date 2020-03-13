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

#include "scpi_export.h"
#include "socket_api_high.h"

namespace scpi {
enum class io_interface { undefined, tcp_ip, usbtmc, rs232 };

class SCPI_API io final {
 public:
  io() = default;
  void open(const std::string &, const unsigned short);
  void write(const std::string &) const;
  void read(std::string &, const unsigned int) const;
  void flush() const;
  void close();
  bool is_opened() const noexcept;
  io_interface get_io_type() const noexcept;

  io(const io &) = delete;
  io &operator=(const io &) = delete;

 private:
  static const unsigned short _read_line_max{1024};
  void write_tcp(const std::string &) const;
  void read_tcp(std::string &, const unsigned int) const;
  io_interface _interface_type{io_interface::undefined};
  bool _is_opened{};
  SOCKET _socket{};
};
}  // namespace scpi
