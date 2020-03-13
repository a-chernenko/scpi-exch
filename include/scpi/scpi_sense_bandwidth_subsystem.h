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
class SCPI_API SENSeBANDwidthSubsystem {
 public:
  SENSeBANDwidthSubsystem(const scpi_base &);
  void set_resolution(const double, const channel_type &channel = {}) const;
  double get_resolution(const channel_type &channel = {}) const;
  void set_resolution_auto(const bool, const channel_type &channel = {}) const;
  bool get_resolution_auto(const channel_type &channel = {}) const;
  void set_video(const double, const channel_type &channel = {}) const;
  double get_video(const channel_type &channel = {}) const;
  void set_video_auto(const bool, const channel_type &channel = {}) const;
  bool get_video_auto(const channel_type &channel = {}) const;

  SENSeBANDwidthSubsystem() = delete;
  SENSeBANDwidthSubsystem(const SENSeBANDwidthSubsystem &) = delete;
  SENSeBANDwidthSubsystem &operator=(const SENSeBANDwidthSubsystem &) = delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace scpi
