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

#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>
#include "scpi_export.h"
#include "socket_api_high.h"

namespace Hardware {
enum class InterfaceType { UNDEFINED, TCPIP, USBTMC, RS232 };

class SCPI_API CHardware final {
 public:
  CHardware() = default;
  void Open(const std::string &, const unsigned short);
  void WriteLine(const std::string &) const;
  void ReadLine(std::string &, const unsigned int) const;
  void Flush() const;
  void Close();
  bool IsOpened() const noexcept;
  InterfaceType GetInterfaceType() const noexcept;

  CHardware(const CHardware &) = delete;
  CHardware &operator=(const CHardware &) = delete;

 private:
  static const unsigned short ReadLineMax{1024};
  void WriteLineTCP(const std::string &) const;
  void ReadLineTCP(std::string &, const unsigned int) const;
  InterfaceType m_InterfaceType{InterfaceType::UNDEFINED};
  bool m_IsOpened{};
  SOCKET m_Socket{};
};
}  // namespace Hardware

#endif  // HARDWARE_H
