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

#ifndef SCPI_SOURCE_LEVEL_COMMANDS_H
#define SCPI_SOURCE_LEVEL_COMMANDS_H

#include "scpi_base.h"

namespace scpi {
template <std::size_t N, const const_string<N> &topsubsystem,
          typename UnitsType>
class CSOURceLEVelCommands {
 public:
  CSOURceLEVelCommands(const scpi_base &);
  void Set(const double, const ChannelType &channel = {}) const;
  void Set(const double, const UnitsType &) const;
  double Get(const ChannelType &channel = {}) const;
  double GetMaximum(const ChannelType &channel = {}) const;
  double GetMinimum(const ChannelType &channel = {}) const;

  CSOURceLEVelCommands() = delete;
  CSOURceLEVelCommands(const CSOURceLEVelCommands &) = delete;
  CSOURceLEVelCommands &operator=(const CSOURceLEVelCommands &) = delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace Scpi

#include "scpi_source_level_commands.hpp"

#endif  // SCPI_SOURCE_LEVEL_COMMANDS_H
