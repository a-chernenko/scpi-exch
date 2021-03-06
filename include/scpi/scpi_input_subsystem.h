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

namespace scpi {
class SCPI_API INPutSubsystem {
 public:
  INPutSubsystem(const scpi_base &);
  void set_impedance(const double, const channel_type &channel = {}) const;
  double get_impedance(const channel_type &channel = {}) const;
  void set_attenuation(const double, const channel_type &channel = {}) const;
  double get_attenuation(const channel_type &channel = {}) const;
  void set_attenuation_auto(const bool, const channel_type &channel = {}) const;
  bool get_attenuation_auto(const channel_type &channel = {}) const;

  INPutSubsystem() = delete;
  INPutSubsystem(const INPutSubsystem &) = delete;
  INPutSubsystem &operator=(const INPutSubsystem &) = delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace scpi
