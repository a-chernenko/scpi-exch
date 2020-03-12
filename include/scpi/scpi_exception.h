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

#ifndef SCPI_EXCEPTION_H
#define SCPI_EXCEPTION_H

#include <exception>
#include "scpi_export.h"

namespace ScpiException {
class SCPI_API CScpiException : public std::exception {
 public:
  CScpiException() = default;
  CScpiException(const CScpiException &) = default;
  explicit CScpiException(const char[]);
  const char *what() const noexcept final;

  CScpiException(CScpiException &&) = delete;
  CScpiException &operator=(const CScpiException &) = delete;

 private:
  const char *const message{"SCPI Error"};
};

struct SCPI_API CommandError final : public CScpiException {
  CommandError();
};

struct SCPI_API QueryError final : public CScpiException {
  QueryError();
};

struct SCPI_API ExecutionError final : public CScpiException {
  ExecutionError();
};

struct SCPI_API DeviceDependentError final : public CScpiException {
  DeviceDependentError();
};
}  // namespace ScpiException

#endif  // SCPI_EXCEPTION_H
