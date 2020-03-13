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
using namespace mnemonics::Unit;

CUNITSubsystem::CUNITSubsystem(const scpi_base &scpi) :_scpi{scpi} {}

void CUNITSubsystem::ToUpperCase(std::string &data) const {
  std::locale loc;
  for (char &ch : data) ch = std::toupper(ch, loc);
}

void CUNITSubsystem::SetCurrent(const CurrentUnitsType::Type &type) const {
  constexpr auto mnemonic = Mnemonics::CURRent.CommandMnemonic;
 _scpi.command(mnemonic, type);
}

void CUNITSubsystem::SetPower(const PowerUnitsType::Type &type) const {
  constexpr auto mnemonic = Mnemonics::POWer.CommandMnemonic;
 _scpi.command(mnemonic, type);
}

void CUNITSubsystem::SetVoltage(const VoltageUnitsType::Type &type) const {
  constexpr auto mnemonic = Mnemonics::VOLTage.CommandMnemonic;
 _scpi.command(mnemonic, type);
}

CurrentUnitsType::Type CUNITSubsystem::GetCurrent() const {
  constexpr auto mnemonic = Mnemonics::CURRent.QueryMnemonic;
  std::string type;
 _scpi.query(mnemonic, type);
  ToUpperCase(type);
  if (type == CurrentUnitsType::uA.c_str())
    return CurrentUnitsType::uA;
  else if (type == CurrentUnitsType::mA.c_str())
    return CurrentUnitsType::mA;
  else if (type == CurrentUnitsType::A.c_str())
    return CurrentUnitsType::A;
  throw std::logic_error("CurrentUnitsType unknown value");
}

PowerUnitsType::Type CUNITSubsystem::GetPower() const {
  constexpr auto mnemonic = Mnemonics::POWer.QueryMnemonic;
  std::string type;
 _scpi.query(mnemonic, type);
  ToUpperCase(type);
  if (type == PowerUnitsType::dB.c_str())
    return PowerUnitsType::dB;
  else if (type == PowerUnitsType::dBm.c_str())
    return PowerUnitsType::dBm;
  else if (type == PowerUnitsType::dBmV.c_str())
    return PowerUnitsType::dBmV;
  else if (type == PowerUnitsType::dBuV.c_str())
    return PowerUnitsType::dBuV;
  else if (type == PowerUnitsType::dBuVEMF.c_str())
    return PowerUnitsType::dBuVEMF;
  else if (type == PowerUnitsType::V.c_str())
    return PowerUnitsType::V;
  else if (type == PowerUnitsType::W.c_str())
    return PowerUnitsType::W;
  throw std::logic_error("PowerUnitsType unknown value");
}

VoltageUnitsType::Type CUNITSubsystem::GetVoltage() const {
  constexpr auto mnemonic = Mnemonics::VOLTage.QueryMnemonic;
  std::string type;
 _scpi.query(mnemonic, type);
  ToUpperCase(type);
  if (type == VoltageUnitsType::uV.c_str())
    return VoltageUnitsType::uV;
  else if (type == VoltageUnitsType::mV.c_str())
    return VoltageUnitsType::mV;
  else if (type == VoltageUnitsType::V.c_str())
    return VoltageUnitsType::V;
  throw std::logic_error("VoltageUnitsType unknown value");
}
