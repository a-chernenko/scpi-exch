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

#include "scpi_units_type.h"

using namespace scpi;

const frequency_units::type frequency_units::Hz{"HZ"};
const frequency_units::type frequency_units::kHz{"KHZ"};
const frequency_units::type frequency_units::MHz{"MHZ"};
const frequency_units::type frequency_units::GHz{"GHZ"};

const current_units::type current_units::A{"A"};
const current_units::type current_units::mA{"MA"};
const current_units::type current_units::uA{"UA"};

const power_units::type power_units::dB{"DB"};
const power_units::type power_units::dBm{"DBM"};
const power_units::type power_units::dBmV{"DBMV"};
const power_units::type power_units::dBuV{"DBUV"};
const power_units::type power_units::dBuVEMF{"DBUVEMF"};
const power_units::type power_units::V{"V"};
const power_units::type power_units::W{"W"};

const voltage_units::type voltage_units::V{"V"};
const voltage_units::type voltage_units::mV{"MV"};
const voltage_units::type voltage_units::uV{"UV"};

const temperature_units::type temperature_units::C{"CEL"};
const temperature_units::type temperature_units::F{"FAR"};
const temperature_units::type temperature_units::K{"K"};

const time_units::type time_units::H{"HOUR"};
const time_units::type time_units::M{"MIN"};
const time_units::type time_units::S{"SEC"};

const angle_units::type angle_units::deg{"DEG"};
const angle_units::type angle_units::rad{"RAD"};
