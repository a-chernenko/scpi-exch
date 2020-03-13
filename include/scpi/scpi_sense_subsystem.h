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

#ifndef SCPI_SENSE_SUBSYSTEM_H
#define SCPI_SENSE_SUBSYSTEM_H

#include "scpi_sense_bandwidth_subsystem.h"
#include "scpi_sense_frequency_subsystem.h"
#include "scpi_sense_sweep_subsystem.h"


namespace scpi {
class SCPI_API CSENSeSubsystem {
 public:
  CSENSeSubsystem(const scpi_base&);
  CSENSeFREQuencySubsystem m_FREQuency;
  CSENSeSWEepSubsystem m_SWEep;
  CSENSeBANDwidthSubsystem m_BANDwidth;

  CSENSeSubsystem() = delete;
  CSENSeSubsystem(const CSENSeSubsystem&) = delete;
  CSENSeSubsystem& operator=(const CSENSeSubsystem&) = delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace Scpi

#endif  // SCPI_SENSE_SUBSYSTEM_H
