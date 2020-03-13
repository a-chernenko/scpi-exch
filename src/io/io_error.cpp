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

#include "io_error.h"

using namespace scpi;

io_error::io_error(const char _message[]) : _message{_message} {}

const char *io_error::what() const noexcept { return _message; }

io_not_supported::io_not_supported() : io_error{"interface not supported"} {}

io_not_opened::io_not_opened() : io_error{"interface not opened"} {}

io_already_opened::io_already_opened()
    : io_error{"interface already is opened"} {}

open_error::open_error() : io_error{"open error"} {}

write_error::write_error() : io_error{"write error"} {}

read_error::read_error() : io_error{"read error"} {}

read_line_exceeded::read_line_exceeded() : io_error{"read line exceeded"} {}

read_timeout::read_timeout() : io_error{"read timeout"} {}

close_error::close_error() : io_error{"close error"} {}

socket_error::socket_error() : io_error{"socket error"} {}

bad_parameters::bad_parameters() : io_error{"bad parametrs"} {}

socket_closed::socket_closed() : io_error{"socket closed"} {}
