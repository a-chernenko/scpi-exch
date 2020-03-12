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

#ifndef SCPI_SOURCE_PROTECTION_COMMANDS_H
#define SCPI_SOURCE_PROTECTION_COMMANDS_H

#include "scpi_base.h"

namespace Scpi {
template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
class CSOURcePROTectionCommands {
 public:
  CSOURcePROTectionCommands(const CScpiBase &);
  void Clear(const ChannelType &channel = {}) const;
  bool IsTripped(const ChannelType &channel = {}) const;
  void SetState(const bool, const ChannelType &channel = {}) const;
  bool GetState(const ChannelType &channel = {}) const;
  void SetLevel(const double, const ChannelType &channel = {}) const;
  void SetLevel(const double, const UnitsType &) const;
  double GetLevel(const ChannelType &channel = {}) const;

  CSOURcePROTectionCommands() = delete;
  CSOURcePROTectionCommands(const CSOURcePROTectionCommands &) = delete;
  CSOURcePROTectionCommands &operator=(const CSOURcePROTectionCommands &) =
      delete;

 private:
  const CScpiBase &m_Scpi;
};
}  // namespace Scpi

#include "scpi_source_protection_commands.hpp"

#endif  // SCPI_SOURCE_PROTECTION_COMMANDS_H
