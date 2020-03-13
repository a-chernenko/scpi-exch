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

#include "scpi_unit_subsystem.h"
#include <locale>
#include <stdexcept>
#include "scpi_unit_mnemonics.h"

using namespace scpi;
using namespace unit;

UNITSubsystem::UNITSubsystem(const scpi_base &scpi) : _scpi{scpi} {}

void UNITSubsystem::to_uppercase(std::string &data) const {
  std::locale loc;
  for (char &ch : data) ch = std::toupper(ch, loc);
}

void UNITSubsystem::set_current(const current_units::type &type) const {
  constexpr auto mnemonic = mnemonics::CURRent.CommandMnemonic;
  _scpi.command(mnemonic, type);
}

void UNITSubsystem::set_power(const power_units::type &type) const {
  constexpr auto mnemonic = mnemonics::POWer.CommandMnemonic;
  _scpi.command(mnemonic, type);
}

void UNITSubsystem::set_voltage(const voltage_units::type &type) const {
  constexpr auto mnemonic = mnemonics::VOLTage.CommandMnemonic;
  _scpi.command(mnemonic, type);
}

current_units::type UNITSubsystem::get_current() const {
  constexpr auto mnemonic = mnemonics::CURRent.QueryMnemonic;
  std::string type;
  _scpi.query(mnemonic, type);
  to_uppercase(type);
  if (type == current_units::uA.c_str())
    return current_units::uA;
  else if (type == current_units::mA.c_str())
    return current_units::mA;
  else if (type == current_units::A.c_str())
    return current_units::A;
  throw std::logic_error("current_units unknown value");
}

power_units::type UNITSubsystem::get_power() const {
  constexpr auto mnemonic = mnemonics::POWer.QueryMnemonic;
  std::string type;
  _scpi.query(mnemonic, type);
  to_uppercase(type);
  if (type == power_units::dB.c_str())
    return power_units::dB;
  else if (type == power_units::dBm.c_str())
    return power_units::dBm;
  else if (type == power_units::dBmV.c_str())
    return power_units::dBmV;
  else if (type == power_units::dBuV.c_str())
    return power_units::dBuV;
  else if (type == power_units::dBuVEMF.c_str())
    return power_units::dBuVEMF;
  else if (type == power_units::V.c_str())
    return power_units::V;
  else if (type == power_units::W.c_str())
    return power_units::W;
  throw std::logic_error("power_units unknown value");
}

voltage_units::type UNITSubsystem::get_voltage() const {
  constexpr auto mnemonic = mnemonics::VOLTage.QueryMnemonic;
  std::string type;
  _scpi.query(mnemonic, type);
  to_uppercase(type);
  if (type == voltage_units::uV.c_str())
    return voltage_units::uV;
  else if (type == voltage_units::mV.c_str())
    return voltage_units::mV;
  else if (type == voltage_units::V.c_str())
    return voltage_units::V;
  throw std::logic_error("voltage_units unknown value");
}
