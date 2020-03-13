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

const FrequencyUnitsType::Type FrequencyUnitsType::Hz{"HZ"};
const FrequencyUnitsType::Type FrequencyUnitsType::kHz{"KHZ"};
const FrequencyUnitsType::Type FrequencyUnitsType::MHz{"MHZ"};
const FrequencyUnitsType::Type FrequencyUnitsType::GHz{"GHZ"};

const CurrentUnitsType::Type CurrentUnitsType::A{"A"};
const CurrentUnitsType::Type CurrentUnitsType::mA{"MA"};
const CurrentUnitsType::Type CurrentUnitsType::uA{"UA"};

const PowerUnitsType::Type PowerUnitsType::dB{"DB"};
const PowerUnitsType::Type PowerUnitsType::dBm{"DBM"};
const PowerUnitsType::Type PowerUnitsType::dBmV{"DBMV"};
const PowerUnitsType::Type PowerUnitsType::dBuV{"DBUV"};
const PowerUnitsType::Type PowerUnitsType::dBuVEMF{"DBUVEMF"};
const PowerUnitsType::Type PowerUnitsType::V{"V"};
const PowerUnitsType::Type PowerUnitsType::W{"W"};

const VoltageUnitsType::Type VoltageUnitsType::V{"V"};
const VoltageUnitsType::Type VoltageUnitsType::mV{"MV"};
const VoltageUnitsType::Type VoltageUnitsType::uV{"UV"};

const TemperatureUnitsType::Type TemperatureUnitsType::C{"CEL"};
const TemperatureUnitsType::Type TemperatureUnitsType::F{"FAR"};
const TemperatureUnitsType::Type TemperatureUnitsType::K{"K"};

const TimeUnitsType::Type TimeUnitsType::H{"HOUR"};
const TimeUnitsType::Type TimeUnitsType::M{"MIN"};
const TimeUnitsType::Type TimeUnitsType::S{"SEC"};

const AngleUnitsType::Type AngleUnitsType::Deg{"DEG"};
const AngleUnitsType::Type AngleUnitsType::Rad{"RAD"};
