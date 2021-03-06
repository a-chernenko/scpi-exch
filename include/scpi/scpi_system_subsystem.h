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

#include "scpi_base.h"

namespace scpi {
class SCPI_API SYSTemSubsystem {
 public:
  SYSTemSubsystem(const scpi_base &);
  class SCPI_API CERRor {
   public:
    CERRor(const scpi_base &scpi);
    void get_next(int &errorCode, std::string &errorMessage) const;
    int get_count() const;

    CERRor() = delete;
    CERRor(const CERRor &) = delete;
    CERRor &operator=(const CERRor &) = delete;

   private:
    const scpi_base &_scpi;
  } ERRor;
  class SCPI_API CLOCK {
   public:
    CLOCK(const scpi_base &scpi);
    void lock() const;
    void release() const;

    CLOCK() = delete;
    CLOCK(const CLOCK &) = delete;
    CLOCK &operator=(const CLOCK &) = delete;

   private:
    const scpi_base &_scpi;
  } LOCK;

  SYSTemSubsystem() = delete;
  SYSTemSubsystem(const SYSTemSubsystem &) = delete;
  SYSTemSubsystem &operator=(const SYSTemSubsystem &) = delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace scpi
