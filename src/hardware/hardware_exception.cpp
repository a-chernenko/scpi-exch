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

#include "hardware_exception.h"

using namespace HardwareException;

CHardwareException::CHardwareException(const char message[])
    : message{message} {}

const char *CHardwareException::what() const noexcept { return message; }

InterfaceNotSupported::InterfaceNotSupported()
    : CHardwareException{"Interface Not Suppored"} {}

InterfaceNotOpened::InterfaceNotOpened()
    : CHardwareException{"Interface Not Opened"} {}

InterfaceAlreadyIsOpened::InterfaceAlreadyIsOpened()
    : CHardwareException{"Interface Already Is Opened"} {}

OpenError::OpenError() : CHardwareException{"Open Error"} {}

WriteError::WriteError() : CHardwareException{"Write Error"} {}

ReadError::ReadError() : CHardwareException{"Read Error"} {}

ReadLineExceeded::ReadLineExceeded()
    : CHardwareException{"Read Line Exceeded"} {}

ReadTimeout::ReadTimeout() : CHardwareException{"Read Timeout"} {}

CloseError::CloseError() : CHardwareException{"Close Error"} {}

SocketError::SocketError() : CHardwareException{"Socket Error"} {}

WrongParametrs::WrongParametrs() : CHardwareException{"Wrong Parametrs"} {}

SocketClosed::SocketClosed() : CHardwareException{"Socket Closed"} {}
