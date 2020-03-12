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

#ifndef IEEE4882_REGISTERS_TYPE_H
#define IEEE4882_REGISTERS_TYPE_H

#include "register_type.h"

namespace Ieee4882RegistersType {
namespace Detail {
enum class StatusByteRegisterBitMask : RegisterType::Register8BitType {
  _DeviceSpecific_0 = (1UL << 0),
  _DeviceSpecific_1 = (1UL << 1),
  ErrorEventQueueMessageAvailable = (1UL << 2),
  QuestionableStatus = (1UL << 3),
  MessageAvailable = (1UL << 4),
  StandardEventStatusRegister = (1 << 5),
  ServiceRequest = (1UL << 6),
  OperationStaus = (1UL << 7),
  AllBits = (_DeviceSpecific_0 | _DeviceSpecific_1 |
             ErrorEventQueueMessageAvailable | QuestionableStatus |
             MessageAvailable | StandardEventStatusRegister | OperationStaus)
};
struct StatusByteRegisterBitsType {
  const bool _DeviceSpecific_0 : 1;
  const bool _DeviceSpecific_1 : 1;
  bool ErrorEventQueueMessageAvailable : 1;
  bool QuestionableStatus : 1;
  bool MessageAvailable : 1;
  bool StandardEventStatusRegister : 1;
  bool ServiceRequest : 1;
  bool OperationStatus : 1;
};
enum class EventStatusRegisterBitMask : RegisterType::Register8BitType {
  OperationComplete = (1UL << 0),
  RequestControl = (1UL << 1),
  QueryError = (1UL << 2),
  DeviceDependentError = (1UL << 3),
  ExecutionError = (1UL << 4),
  CommandError = (1UL << 5),
  UserRequest = (1UL << 6),
  PowerOn = (1UL << 7),
  AllBits =
      (OperationComplete | RequestControl | QueryError | DeviceDependentError |
       ExecutionError | CommandError | UserRequest | PowerOn)
};
struct EventStatusRegisterBitsType {
  bool OperationComplete : 1;
  bool RequestControl : 1;
  bool QueryError : 1;
  bool DeviceDependentError : 1;
  bool ExecutionError : 1;
  bool CommandError : 1;
  bool UserRequest : 1;
  bool PowerOn : 1;
};
}  // namespace Detail

using EventStatusRegisterType =
    RegisterType::Register8BitTypeAbstract<Detail::EventStatusRegisterBitMask,
                                           Detail::EventStatusRegisterBitsType>;

using StatusByteRegisterType =
    RegisterType::Register8BitTypeAbstract<Detail::StatusByteRegisterBitMask,
                                           Detail::StatusByteRegisterBitsType>;
}  // namespace Ieee4882RegistersType

#endif  // IEEE4882_REGISTERS_TYPE_H
