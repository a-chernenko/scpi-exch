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

#include "hardware.h"
#include "hardware_exception.h"

using std::string;
using namespace Hardware;
using namespace HardwareException;

void CHardware::Open(const string &ip, const unsigned short port) {
  if (m_IsOpened) throw InterfaceAlreadyIsOpened();
  auto result = CreateTcpClient(&m_Socket, ip.data(), 0, port);
  if (result < 0) throw OpenError();
  m_IsOpened = true;
  m_InterfaceType = InterfaceType::TCPIP;
}

void CHardware::WriteLine(const string &data) const {
  if (!m_IsOpened) throw InterfaceNotOpened();
  string write_data{data};
  write_data.push_back('\n');
  switch (m_InterfaceType) {
    case InterfaceType::TCPIP:
      WriteLineTCP(write_data);
      break;
    case InterfaceType::USBTMC:
    case InterfaceType::RS232:
    case InterfaceType::UNDEFINED:
    default:
      throw InterfaceNotSupported();
  }
}

void CHardware::ReadLine(string &data, const unsigned int timeouts_mS) const {
  if (!m_IsOpened) throw InterfaceNotOpened();
  if (!data.empty()) data.clear();
  switch (m_InterfaceType) {
    case InterfaceType::TCPIP:
      ReadLineTCP(data, timeouts_mS);
      break;
    case InterfaceType::USBTMC:
    case InterfaceType::RS232:
    case InterfaceType::UNDEFINED:
    default:
      throw InterfaceNotSupported();
  }
}

void CHardware::Flush() const {
  if (!m_IsOpened) throw InterfaceNotOpened();
  switch (m_InterfaceType) {
    case InterfaceType::TCPIP:
    case InterfaceType::USBTMC:
    case InterfaceType::RS232:
    case InterfaceType::UNDEFINED:
      break;
    default:
      throw InterfaceNotSupported();
  }
}

void CHardware::Close() {
  if (m_IsOpened && m_Socket) {
    if (DestroySock(m_Socket) < 0) throw CloseError();
    m_IsOpened = false;
    m_Socket = 0;
    m_InterfaceType = InterfaceType::UNDEFINED;
  }
}

bool CHardware::IsOpened() const noexcept { return m_IsOpened; }

InterfaceType CHardware::GetInterfaceType() const noexcept {
  return m_InterfaceType;
}

void CHardware::WriteLineTCP(const string &data) const {
  auto result = SendTcp(m_Socket, data.c_str(), data.length(), 0);
  if (result < static_cast<int>(data.size())) throw WriteError();
}

void CHardware::ReadLineTCP(string &data,
                            const unsigned int timeouts_mS) const {
  char ch{'\0'};
  auto count = ReadLineMax;
  do {
    auto result = RecvTcpTime(m_Socket, &ch, sizeof(char), timeouts_mS);
    if (result == RECV_TCP_TIME_TIME_OUT)
      throw ReadTimeout();
    else if (result != RECV_TCP_TIME_OK) {
      switch (result) {
        case RECV_TCP_TIME_CRITICAL_ERROR:
          throw SocketError();
        case RECV_TCP_TIME_WRONG_INPUT_PARAMETERS:
          throw WrongParametrs();
        case RECV_TCP_TIME_SOCKET_GRACEFULLY_CLOSED:
          throw SocketClosed();
        default:
          throw ReadError();
      }
    }
    if (ch == '\n') break;
    data.push_back(ch);
  } while (--count);
  if (count == 0) throw ReadLineExceeded();
}
