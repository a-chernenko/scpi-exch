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

#include "scpi_system_subsystem.h"
#include "scpi_system_mnemonics.h"

using std::string;
using namespace scpi;
using namespace mnemonics::System;

CSYSTemSubsystem::CSYSTemSubsystem(const scpi_base &scpi)
    : ERRor{scpi}, LOCK{scpi}, _scpi{scpi} {}

CSYSTemSubsystem::CERRor::CERRor(const scpi_base &scpi) : _scpi{scpi} {}

CSYSTemSubsystem::CLOCK::CLOCK(const scpi_base &scpi) : _scpi{scpi} {}

void CSYSTemSubsystem::CERRor::GetNext(int &errorCode,
                                       string &errorMessage) const {
  constexpr auto mnemonic = Mnemonics::ERRor.QueryMnemonic;
  string _message;
  _scpi.query(mnemonic, _message);
  string::size_type index{};
  errorCode = std::stoi(_message, &index);
  errorMessage = _message.substr(++index);
  scpi_base::remove_quotes(errorMessage);
}

int CSYSTemSubsystem::CERRor::GetCount() const {
  constexpr auto mnemonic = Mnemonics::ERRor.COUNt.QueryMnemonic;
  int value;
  _scpi.query(mnemonic, value);
  return value;
}

void CSYSTemSubsystem::CLOCK::Lock() const {
  constexpr auto mnemonic = Mnemonics::LOCK.Mnemonic;
  _scpi.command(mnemonic);
}

void CSYSTemSubsystem::CLOCK::Release() const {
  constexpr auto mnemonic = Mnemonics::LOCK.RELease.Mnemonic;
  _scpi.command(mnemonic);
}
