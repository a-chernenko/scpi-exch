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

#ifndef SCPI_MEASURE_SUBSYSTEM_H
#define SCPI_MEASURE_SUBSYSTEM_H

#include "scpi_base.h"

namespace Scpi {
class SCPI_API CMEASureSubsystem {
 public:
  CMEASureSubsystem(const CScpiBase &);

  double Read(const unsigned int, const ChannelType &channel = {}) const;
  double CurrentDC(const ChannelType &channel = {}) const;
  double VoltageDC(const ChannelType &channel = {}) const;
  double PowerDC(const ChannelType &channel = {}) const;

  CMEASureSubsystem() = delete;
  CMEASureSubsystem(const CMEASureSubsystem &) = delete;
  CMEASureSubsystem &operator=(const CMEASureSubsystem &) = delete;

 private:
  const CScpiBase &m_Scpi;
};
}  // namespace Scpi

#endif  // SCPI_MEASURE_SUBSYSTEM_H
