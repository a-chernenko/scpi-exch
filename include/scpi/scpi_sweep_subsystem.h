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
class SCPI_API SWEepSubsystem {
 public:
  void set_points(const double, const channel_type &channel = {}) const;
  double get_points(const channel_type &channel = {}) const;
  void set_step(const double, const channel_type &channel = {}) const;
  double get_step(const channel_type &channel = {}) const;
  void set_count(const double, const channel_type &channel = {}) const;
  double get_count(const channel_type &channel = {}) const;

  class SCPI_API CTIME {
   public:
    CTIME(const scpi_base &scpi);
    void set(const double, const channel_type &channel = {}) const;
    double get(const channel_type &channel = {}) const;
    void set_auto(const bool, const channel_type &channel = {}) const;
    bool get_auto(const channel_type &channel = {}) const;

    CTIME() = delete;
    CTIME(const CTIME &) = delete;
    CTIME &operator=(const CTIME &) = delete;

   private:
    const scpi_base &_scpi;
  } TIME;

  SWEepSubsystem() = delete;
  SWEepSubsystem(const SWEepSubsystem &) = delete;
  SWEepSubsystem &operator=(const SWEepSubsystem &) = delete;

 protected:
  SWEepSubsystem(const scpi_base &);
  const scpi_base &_scpi;
};
}  // namespace scpi
