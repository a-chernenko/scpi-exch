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

#include <exception>

#include "scpi_export.h"

namespace scpi {
class SCPI_API io_error : public std::exception {
 public:
  io_error() = default;
  io_error(const io_error &) = default;
  explicit io_error(const char[]);
  const char *what() const noexcept final;

  io_error(io_error &&) = delete;
  io_error &operator=(const io_error &) = delete;

 private:
  const char *const _message{"scpi io error"};
};

struct SCPI_API io_not_supported final : io_error {
  io_not_supported();
};

struct SCPI_API io_not_opened final : io_error {
  io_not_opened();
};

struct SCPI_API io_already_opened final : io_error {
  io_already_opened();
};

struct SCPI_API open_error final : io_error {
  open_error();
};

struct SCPI_API write_error final : io_error {
  write_error();
};

struct SCPI_API read_error final : io_error {
  read_error();
};

struct SCPI_API read_line_exceeded final : io_error {
  read_line_exceeded();
};

struct SCPI_API read_timeout final : io_error {
  read_timeout();
};

struct SCPI_API close_error final : io_error {
  close_error();
};

struct SCPI_API socket_error final : io_error {
  socket_error();
};

struct SCPI_API bad_parameters final : io_error {
  bad_parameters();
};

struct SCPI_API socket_closed final : io_error {
  socket_closed();
};
}  // namespace scpi
