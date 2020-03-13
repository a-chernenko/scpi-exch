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

#include "register_type.h"

namespace ScpiRegistersType {
namespace detail {
enum class QUEStionableStatusRegisterBitMask : scpi::register_16bit_type {
  VOLTage = (1UL << 0),
  CURRent = (1UL << 1),
  TIME = (1UL << 2),
  POWer = (1UL << 3),
  TEMPerature = (1UL << 4),
  FREQuency = (1UL << 5),
  PHASe = (1UL << 6),
  MODulation = (1UL << 7),
  CALibration = (1UL << 8),
  INSTrumentSummary = (1UL << 13),
  CommandWarning = (1UL << 14),
  all_bits =
      (VOLTage | CURRent | TIME | POWer | TEMPerature | FREQuency | PHASe |
       MODulation | CALibration | INSTrumentSummary | CommandWarning)
};
struct QUEStionableStatusRegisterBitsType {
  bool VOLTage : 1;
  bool CURRent : 1;
  bool TIME : 1;
  bool POWer : 1;
  bool TEMPerature : 1;
  bool FREQuency : 1;
  bool PHASe : 1;
  bool MODulation : 1;
  bool CALibration : 1;
  const bool device_specific_9 : 1;
  const bool device_specific_10 : 1;
  const bool device_specific_11 : 1;
  const bool device_specific_12 : 1;
  bool INSTrumentSummary : 1;
  bool CommandWarning : 1;
  const bool _NOT_USED : 1;
};
enum class OPERationStatusRegisterBitMask : scpi::register_16bit_type {
  CALibrating = (1UL << 0),
  SETTing = (1UL << 1),
  RANGing = (1UL << 2),
  SWEeping = (1UL << 3),
  MEASuring = (1UL << 4),
  TRIGgerWaitingSummary = (1UL << 5),
  ARMWaitingSummary = (1UL << 6),
  CORRecting = (1UL << 7),
  INSTrumentSummary = (1UL << 13),
  PROGramRunning = (1UL << 14),
  all_bits = (CALibrating | SETTing | RANGing | SWEeping | MEASuring |
              TRIGgerWaitingSummary | ARMWaitingSummary | CORRecting |
              INSTrumentSummary | PROGramRunning)
};
struct OPERationStatusRegisterBitsType {
  bool CALibrating : 1;
  bool SETTing : 1;
  bool RANGing : 1;
  bool SWEeping : 1;
  bool MEASuring : 1;
  bool TRIGgerWaitingSummary : 1;
  bool ARMWaitingSummary : 1;
  bool CORRecting : 1;
  const bool device_specific_8 : 1;
  const bool device_specific_9 : 1;
  const bool device_specific_10 : 1;
  const bool device_specific_11 : 1;
  const bool device_specific_12 : 1;
  bool INSTrumentSummary : 1;
  bool PROGramRunning : 1;
  const bool _NOT_USED : 1;
};
}  // namespace detail

using QUEStionable_status_register =
    scpi::register_16bit_abstract<detail::QUEStionableStatusRegisterBitMask,
                                  detail::QUEStionableStatusRegisterBitsType>;

using OPERation_status_register =
    scpi::register_16bit_abstract<detail::OPERationStatusRegisterBitMask,
                                  detail::OPERationStatusRegisterBitsType>;
}  // namespace ScpiRegistersType
