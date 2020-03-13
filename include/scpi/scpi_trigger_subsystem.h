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

#ifndef SCPI_TRIGGER_SUBSYSTEM_H
#define SCPI_TRIGGER_SUBSYSTEM_H

#include "scpi_base.h"

namespace scpi {
class SCPI_API CTRIGgerSubsystem {
 public:
  CTRIGgerSubsystem(const scpi_base&);
  void Initiate() const;
  void Abort() const;

  CTRIGgerSubsystem() = delete;
  CTRIGgerSubsystem(const CTRIGgerSubsystem&) = delete;
  CTRIGgerSubsystem& operator=(const CTRIGgerSubsystem&) = delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace Scpi

#endif  // SCPI_TRIGGER_SUBSYSTEM_H
