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

#ifndef SCPI_SWEEP_SUBSYSTEM_H
#define SCPI_SWEEP_SUBSYSTEM_H

#include "scpi_base.h"

namespace Scpi {
class SCPI_API CSWEepSubsystem {
 public:
  void SetPoints(const double, const ChannelType &channel = {}) const;
  double GetPoints(const ChannelType &channel = {}) const;
  void SetStep(const double, const ChannelType &channel = {}) const;
  double GetStep(const ChannelType &channel = {}) const;
  void SetCount(const double, const ChannelType &channel = {}) const;
  double GetGount(const ChannelType &channel = {}) const;

  class SCPI_API CTIME {
   public:
    CTIME(const CScpiBase &scpi);
    void Set(const double, const ChannelType &channel = {}) const;
    double Get(const ChannelType &channel = {}) const;
    void SetAuto(const bool, const ChannelType &channel = {}) const;
    bool GetAuto(const ChannelType &channel = {}) const;

    CTIME() = delete;
    CTIME(const CTIME &) = delete;
    CTIME &operator=(const CTIME &) = delete;

   private:
    const CScpiBase &m_Scpi;
  } m_TIME;

  CSWEepSubsystem() = delete;
  CSWEepSubsystem(const CSWEepSubsystem &) = delete;
  CSWEepSubsystem &operator=(const CSWEepSubsystem &) = delete;

 protected:
  CSWEepSubsystem(const CScpiBase &);
  const CScpiBase &m_Scpi;
};
}  // namespace Scpi

#endif  // SCPI_SWEEP_SUBSYSTEM_H
