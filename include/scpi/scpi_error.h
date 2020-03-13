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
class SCPI_API scpi_error : public std::exception {
 public:
  scpi_error() = default;
  scpi_error(const scpi_error &) = default;
  explicit scpi_error(const char[]);
  const char *what() const noexcept final;

  scpi_error(scpi_error &&) = delete;
  scpi_error &operator=(const scpi_error &) = delete;

 private:
  const char *const _message{"scpi error"};
};

struct SCPI_API command_error final : scpi_error {
  command_error();
};

struct SCPI_API query_error final : scpi_error {
  query_error();
};

struct SCPI_API execution_error final : scpi_error {
  execution_error();
};

struct SCPI_API device_dependent_error final : scpi_error {
  device_dependent_error();
};
}  // namespace scpi
