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

#pragma once

#include "scpi_base.h"
#include "scpi_units_type.h"

namespace scpi {
class SCPI_API FREQuencySubsystem {
 public:
  void set(const double, const channel_type &channel = {}) const;
  void set(const double, const frequency_units::type &) const;
  double get(const channel_type &channel = {}) const;
  void set_start(const double, const channel_type &channel = {}) const;
  double get_start(const channel_type &channel = {}) const;
  void set_stop(const double, const channel_type &channel = {}) const;
  double get_stop(const channel_type &channel = {}) const;
  void set_center(const double, const channel_type &channel = {}) const;
  double get_center(const channel_type &channel = {}) const;
  void set_span(const double, const channel_type &channel = {}) const;
  double get_span(const channel_type &channel = {}) const;
  void set_offset(const double, const channel_type &channel = {}) const;
  double get_offset(const channel_type &channel = {}) const;

  FREQuencySubsystem() = delete;
  FREQuencySubsystem(const FREQuencySubsystem &) = delete;
  FREQuencySubsystem &operator=(const FREQuencySubsystem &) = delete;

 protected:
  FREQuencySubsystem(const scpi_base &);
  const scpi_base &_scpi;
};
}  // namespace scpi
