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
class SCPI_API CSENSeBANDwidthSubsystem {
 public:
  CSENSeBANDwidthSubsystem(const scpi_base &);
  void SetResolution(const double, const ChannelType &channel = {}) const;
  double GetResolution(const ChannelType &channel = {}) const;
  void SetResolutionAuto(const bool, const ChannelType &channel = {}) const;
  bool GetResolutionAuto(const ChannelType &channel = {}) const;
  void SetVideo(const double, const ChannelType &channel = {}) const;
  double GetVideo(const ChannelType &channel = {}) const;
  void SetVideoAuto(const bool, const ChannelType &channel = {}) const;
  bool GetVideoAuto(const ChannelType &channel = {}) const;

  CSENSeBANDwidthSubsystem() = delete;
  CSENSeBANDwidthSubsystem(const CSENSeBANDwidthSubsystem &) = delete;
  CSENSeBANDwidthSubsystem &operator=(const CSENSeBANDwidthSubsystem &) =
      delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace scpi
