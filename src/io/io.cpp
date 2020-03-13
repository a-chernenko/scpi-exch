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

#include "io.h"
#include "io_error.h"

using namespace scpi;

void io::open(const std::string &ip, const unsigned short port) {
  if (_is_opened) throw io_already_opened();
  auto result = CreateTcpClient(&_socket, ip.data(), 0, port);
  if (result < 0) throw open_error();
  _is_opened = true;
  _interface_type = io_interface::tcp_ip;
}

void io::write(const std::string &data) const {
  if (!_is_opened) throw io_not_opened();
  std::string write_data{data};
  write_data.push_back('\n');
  switch (_interface_type) {
    case io_interface::tcp_ip:
      write_tcp(write_data);
      break;
    case io_interface::usbtmc:
    case io_interface::rs232:
    case io_interface::undefined:
    default:
      throw io_not_supported();
  }
}

void io::read(std::string &data, const unsigned int timeouts_ms) const {
  if (!_is_opened) throw io_not_opened();
  if (!data.empty()) data.clear();
  switch (_interface_type) {
    case io_interface::tcp_ip:
      read_tcp(data, timeouts_ms);
      break;
    case io_interface::usbtmc:
    case io_interface::rs232:
    case io_interface::undefined:
    default:
      throw io_not_supported();
  }
}

void io::flush() const {
  if (!_is_opened) throw io_not_opened();
  switch (_interface_type) {
    case io_interface::tcp_ip:
    case io_interface::usbtmc:
    case io_interface::rs232:
    case io_interface::undefined:
      break;
    default:
      throw io_not_supported();
  }
}

void io::close() {
  if (_is_opened && _socket) {
    if (DestroySock(_socket) < 0) throw close_error();
    _is_opened = false;
    _socket = 0;
    _interface_type = io_interface::undefined;
  }
}

bool io::is_opened() const noexcept { return _is_opened; }

io_interface io::get_io_type() const noexcept { return _interface_type; }

void io::write_tcp(const std::string &data) const {
  auto result = SendTcp(_socket, data.c_str(), data.length(), 0);
  if (result < static_cast<int>(data.size())) throw write_error();
}

void io::read_tcp(std::string &data, const unsigned int timeouts_ms) const {
  char ch{'\0'};
  auto count = _read_line_max;
  do {
    auto result = RecvTcpTime(_socket, &ch, sizeof(char), timeouts_ms);
    if (result == RECV_TCP_TIME_TIME_OUT)
      throw read_timeout();
    else if (result != RECV_TCP_TIME_OK) {
      switch (result) {
        case RECV_TCP_TIME_CRITICAL_ERROR:
          throw socket_error();
        case RECV_TCP_TIME_WRONG_INPUT_PARAMETERS:
          throw bad_parameters();
        case RECV_TCP_TIME_SOCKET_GRACEFULLY_CLOSED:
          throw socket_closed();
        default:
          throw read_error();
      }
    }
    if (ch == '\n') break;
    data.push_back(ch);
  } while (--count);
  if (count == 0) throw read_line_exceeded();
}
