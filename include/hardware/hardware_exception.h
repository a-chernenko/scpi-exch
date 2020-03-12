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

#ifndef HARDWARE_EXCEPTION_H
#define HARDWARE_EXCEPTION_H

#include <exception>
#include "scpi_export.h"

namespace HardwareException {
class SCPI_API CHardwareException : public std::exception {
 public:
  CHardwareException() = default;
  CHardwareException(const CHardwareException &) = default;
  explicit CHardwareException(const char[]);
  const char *what() const noexcept final;

  CHardwareException(CHardwareException &&) = delete;
  CHardwareException &operator=(const CHardwareException &) = delete;

 private:
  const char *const message{"Hardware Error"};
};

struct SCPI_API InterfaceNotSupported final : public CHardwareException {
  InterfaceNotSupported();
};

struct SCPI_API InterfaceNotOpened final : public CHardwareException {
  InterfaceNotOpened();
};

struct SCPI_API InterfaceAlreadyIsOpened final : public CHardwareException {
  InterfaceAlreadyIsOpened();
};

struct SCPI_API OpenError final : public CHardwareException {
  OpenError();
};

struct SCPI_API WriteError final : public CHardwareException {
  WriteError();
};

struct SCPI_API ReadError final : public CHardwareException {
  ReadError();
};

struct SCPI_API ReadLineExceeded final : public CHardwareException {
  ReadLineExceeded();
};

struct SCPI_API ReadTimeout final : public CHardwareException {
  ReadTimeout();
};

struct SCPI_API CloseError final : public CHardwareException {
  CloseError();
};

struct SCPI_API SocketError final : public CHardwareException {
  SocketError();
};

struct SCPI_API WrongParametrs final : public CHardwareException {
  WrongParametrs();
};

struct SCPI_API SocketClosed final : public CHardwareException {
  SocketClosed();
};
}  // namespace HardwareException

#endif  // HARDWARE_EXCEPTION_H
