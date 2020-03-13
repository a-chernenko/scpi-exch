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

#include "scpi_current_subsystem.h"
#include "scpi_power_subsystem.h"
#include "scpi_voltage_subsystem.h"

namespace scpi {
class SCPI_API UNITSubsystem {
 public:
  UNITSubsystem(const scpi_base&);
  void set_current(const current_units::type&) const;
  void set_power(const power_units::type&) const;
  void set_voltage(const voltage_units::type&) const;
  current_units::type get_current() const;
  power_units::type get_power() const;
  voltage_units::type get_voltage() const;

  UNITSubsystem() = delete;
  UNITSubsystem(const UNITSubsystem&) = delete;
  UNITSubsystem& operator=(const UNITSubsystem&) = delete;

 private:
  void to_uppercase(std::string&) const;
  const scpi_base& _scpi;
};
}  // namespace scpi
