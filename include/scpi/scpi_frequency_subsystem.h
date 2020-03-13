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

#ifndef SCPI_FREQUENCY_SUBSYSTEM_H
#define SCPI_FREQUENCY_SUBSYSTEM_H

#include "scpi_base.h"
#include "scpi_units_type.h"

namespace scpi {
class SCPI_API CFREQuencySubsystem {
 public:
  void Set(const double, const ChannelType &channel = {}) const;
  void Set(const double, const FrequencyUnitsType::Type &) const;
  double Get(const ChannelType &channel = {}) const;
  void SetStart(const double, const ChannelType &channel = {}) const;
  double GetStart(const ChannelType &channel = {}) const;
  void SetStop(const double, const ChannelType &channel = {}) const;
  double GetStop(const ChannelType &channel = {}) const;
  void SetCenter(const double, const ChannelType &channel = {}) const;
  double GetCenter(const ChannelType &channel = {}) const;
  void SetSpan(const double, const ChannelType &channel = {}) const;
  double GetSpan(const ChannelType &channel = {}) const;
  void SetOffset(const double, const ChannelType &channel = {}) const;
  double GetOffset(const ChannelType &channel = {}) const;

  CFREQuencySubsystem() = default;
  CFREQuencySubsystem(const CFREQuencySubsystem &) = delete;
  CFREQuencySubsystem &operator=(const CFREQuencySubsystem &) = delete;

 protected:
  CFREQuencySubsystem(const scpi_base &);
  const scpi_base &_scpi;
};
}  // namespace Scpi

#endif  // SCPI_FREQUENCY_SUBSYSTEM_H
