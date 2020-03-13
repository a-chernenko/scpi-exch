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
class SCPI_API CUNITSubsystem {
 public:
  CUNITSubsystem(const scpi_base&);
  void SetCurrent(const CurrentUnitsType::Type&) const;
  void SetPower(const PowerUnitsType::Type&) const;
  void SetVoltage(const VoltageUnitsType::Type&) const;
  CurrentUnitsType::Type GetCurrent() const;
  PowerUnitsType::Type GetPower() const;
  VoltageUnitsType::Type GetVoltage() const;

  CUNITSubsystem() = delete;
  CUNITSubsystem(const CUNITSubsystem&) = delete;
  CUNITSubsystem& operator=(const CUNITSubsystem&) = delete;

 private:
  void ToUpperCase(std::string&) const;
  const scpi_base& _scpi;
};
}  // namespace scpi
