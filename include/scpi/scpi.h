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

#ifndef SCPI_H
#define SCPI_H

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


namespace Scpi {
/**
@class CScpi
@brief Реализация протокола SCPI.
*/
class SCPI_API CScpi final : public CScpiBase {
 public:
  using SharedPtr = std::shared_ptr<CScpi>;
  CScpi() = default;
  CSTATusSubsystem m_STATus{*this};
  COUTPutSubsystem m_OUTPut{*this};
  CMEASureSubsystem m_MEASure{*this};
  CSOURceSubsystem m_SOURce{*this};
  CSENSeSubsystem m_SENSe{*this};
  CINPutSubsystem m_INPut{*this};
  CUNITSubsystem m_UNIT{*this};
  CDISPlaySubsystem m_DISPlay{*this};
  CSYSTemSubsystem m_SYSTem{*this};
  CTRIGgerSubsystem m_TRIGger{*this};

  CScpi(const CScpi&) = delete;
  CScpi& operator=(const CScpi&) = delete;
};
}  // namespace Scpi

#endif  // SCPI_H
