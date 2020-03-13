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

#include <ostream>
#include <string>
#include "scpi_export.h"

namespace scpi {
struct units_type_base {
 public:
  explicit units_type_base(const char value[]) : value(value) {}
  std::string to_string() const {
    std::string str(value);
    return str;
  }
  const char *c_str() const { return value; }
  friend std::ostream &operator<<(std::ostream &lhs,
                                  const units_type_base &rhs) {
    lhs << rhs.value;
    return lhs;
  }

  units_type_base() = delete;
  units_type_base(const units_type_base &) = default;
  units_type_base &operator=(const units_type_base &) = default;

 private:
  const char *const value{};
};

struct SCPI_API voltage_units : public units_type_base {
  using type = units_type_base;
  static const type V;
  static const type mV;
  static const type uV;
  voltage_units() = delete;
};

struct SCPI_API power_units : public units_type_base {
  using type = units_type_base;
  static const type dB;
  static const type dBm;
  static const type dBmV;
  static const type dBuV;
  static const type dBuVEMF;
  static const type V;
  static const type W;
  power_units() = delete;
};

struct SCPI_API current_units : public units_type_base {
  using type = units_type_base;
  static const type A;
  static const type mA;
  static const type uA;
  current_units() = delete;
};

struct SCPI_API frequency_units : public units_type_base {
  using type = units_type_base;
  static const type Hz;
  static const type kHz;
  static const type MHz;
  static const type GHz;
  frequency_units() = delete;
};

struct SCPI_API temperature_units : public units_type_base {
  using type = units_type_base;
  static const type C;
  static const type F;
  static const type K;
  temperature_units() = delete;
};

struct SCPI_API time_units : public units_type_base {
  using type = units_type_base;
  static const type H;
  static const type M;
  static const type S;
  time_units() = delete;
};

struct SCPI_API angle_units : public units_type_base {
  using type = units_type_base;
  static const type deg;
  static const type rad;
  angle_units() = delete;
};
}  // namespace scpi
