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

#include "scpi_display_subsystem.h"
#include "scpi_input_subsystem.h"
#include "scpi_measure_subsystem.h"
#include "scpi_output_subsystem.h"
#include "scpi_sense_subsystem.h"
#include "scpi_source_subsystem.h"
#include "scpi_status_subsystem.h"
#include "scpi_system_subsystem.h"
#include "scpi_trigger_subsystem.h"
#include "scpi_unit_subsystem.h"

namespace scpi {
class SCPI_API scpi_io final : public scpi_base {
 public:
  using shared_ptr = std::shared_ptr<scpi_io>;
  scpi_io() = default;
  STATusSubsystem STATus{*this};
  OUTPutSubsystem OUTPut{*this};
  MEASureSubsystem MEASure{*this};
  SOURceSubsystem SOURce{*this};
  SENSeSubsystem SENSe{*this};
  INPutSubsystem INPut{*this};
  UNITSubsystem UNIT{*this};
  DISPlaySubsystem DISPlay{*this};
  SYSTemSubsystem SYSTem{*this};
  TRIGgerSubsystem TRIGger{*this};

  scpi_io(const scpi_io&) = delete;
  scpi_io& operator=(const scpi_io&) = delete;
};
}  // namespace scpi
