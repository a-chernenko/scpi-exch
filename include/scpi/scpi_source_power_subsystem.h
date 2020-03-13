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

#ifndef SCPI_SOURCE_POWER_SUBSYSTEM_H
#define SCPI_SOURCE_POWER_SUBSYSTEM_H

#include "scpi_power_subsystem.h"

namespace scpi {
class SCPI_API CSOURcePOWerSubsystem : public CPOWerSubsystem {
 public:
  CSOURcePOWerSubsystem(const scpi_base&);

  CSOURcePOWerSubsystem() = delete;
  CSOURcePOWerSubsystem(const CSOURcePOWerSubsystem&) = delete;
  CSOURcePOWerSubsystem& operator=(const CSOURcePOWerSubsystem&) = delete;
};
}  // namespace Scpi

#endif  // SCPI_SOURCE_POWER_SUBSYSTEM_H
