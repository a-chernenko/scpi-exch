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

#ifndef SCPI_SYSTEM_SUBSYSTEM_H
#define SCPI_SYSTEM_SUBSYSTEM_H

#include "scpi_base.h"

namespace Scpi {
class SCPI_API CSYSTemSubsystem {
 public:
  CSYSTemSubsystem(const CScpiBase &);
  class SCPI_API CERRor {
   public:
    CERRor(const CScpiBase &scpi);
    void GetNext(int &errorCode, std::string &errorMessage) const;
    int GetCount() const;

    CERRor() = delete;
    CERRor(const CERRor &) = delete;
    CERRor &operator=(const CERRor &) = delete;

   private:
    const CScpiBase &m_Scpi;
  } m_ERRor;
  class SCPI_API LOCK {
   public:
    LOCK(const CScpiBase &scpi);
    void Lock() const;
    void Release() const;

    LOCK() = delete;
    LOCK(const LOCK &) = delete;
    LOCK &operator=(const LOCK &) = delete;

   private:
    const CScpiBase &m_Scpi;
  } m_LOCK;

  CSYSTemSubsystem() = delete;
  CSYSTemSubsystem(const CSYSTemSubsystem &) = delete;
  CSYSTemSubsystem &operator=(const CSYSTemSubsystem &) = delete;

 private:
  const CScpiBase &m_Scpi;
};
}  // namespace Scpi

#endif  // SCPI_SYSTEM_SUBSYSTEM_H
