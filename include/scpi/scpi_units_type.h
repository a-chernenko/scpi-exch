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

#ifndef SCPI_UNITS_TYPE_H
#define SCPI_UNITS_TYPE_H

#include <ostream>
#include <string>
#include "scpi_export.h"


namespace Scpi {
struct UnitsTypeBase {
 public:
  explicit UnitsTypeBase(const char value[]) : value(value) {}
  std::string to_string() const {
    std::string str(value);
    return str;
  }
  const char *c_str() const { return value; }
  friend std::ostream &operator<<(std::ostream &lhs, const UnitsTypeBase &rhs) {
    lhs << rhs.value;
    return lhs;
  }

  UnitsTypeBase() = delete;
  UnitsTypeBase(const UnitsTypeBase &) = default;
  UnitsTypeBase &operator=(const UnitsTypeBase &) = default;

 private:
  const char *const value{};
};

struct SCPI_API VoltageUnitsType : public UnitsTypeBase {
  using Type = UnitsTypeBase;
  static const Type V;
  static const Type mV;
  static const Type uV;
  VoltageUnitsType() = delete;
};

struct SCPI_API PowerUnitsType : public UnitsTypeBase {
  using Type = UnitsTypeBase;
  static const Type dB;
  static const Type dBm;
  static const Type dBmV;
  static const Type dBuV;
  static const Type dBuVEMF;
  static const Type V;
  static const Type W;
  PowerUnitsType() = delete;
};

struct SCPI_API CurrentUnitsType : public UnitsTypeBase {
  using Type = UnitsTypeBase;
  static const Type A;
  static const Type mA;
  static const Type uA;
  CurrentUnitsType() = delete;
};

struct SCPI_API FrequencyUnitsType : public UnitsTypeBase {
  using Type = UnitsTypeBase;
  static const Type Hz;
  static const Type kHz;
  static const Type MHz;
  static const Type GHz;
  FrequencyUnitsType() = delete;
};

struct SCPI_API TemperatureUnitsType : public UnitsTypeBase {
  using Type = UnitsTypeBase;
  static const Type C;
  static const Type F;
  static const Type K;
  TemperatureUnitsType() = delete;
};

struct SCPI_API TimeUnitsType : public UnitsTypeBase {
  using Type = UnitsTypeBase;
  static const Type H;
  static const Type M;
  static const Type S;
  TimeUnitsType() = delete;
};

struct SCPI_API AngleUnitsType : public UnitsTypeBase {
  using Type = UnitsTypeBase;
  static const Type Deg;
  static const Type Rad;
  AngleUnitsType() = delete;
};
}  // namespace Scpi

#endif  // SCPI_UNITS_TYPE_H
