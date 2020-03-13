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

namespace scpi {
namespace ieee488 {
namespace detail {
enum class status_byte_register_bitmask : scpi::register_8bit_type {
  device_specific_0 = (1UL << 0),
  device_specific_1 = (1UL << 1),
  error_event_queue_message_available = (1UL << 2),
  questionable_status = (1UL << 3),
  message_available = (1UL << 4),
  standard_event_status_register = (1 << 5),
  service_request = (1UL << 6),
  operation_status = (1UL << 7),
  all_bits =
      (device_specific_0 | device_specific_1 |
       error_event_queue_message_available | questionable_status |
       message_available | standard_event_status_register | operation_status)
};
struct status_byte_register_bits {
  const bool device_specific_0 : 1;
  const bool device_specific_1 : 1;
  bool error_event_queue_message_available : 1;
  bool questionable_status : 1;
  bool message_available : 1;
  bool standard_event_status_register : 1;
  bool service_request : 1;
  bool operation_status : 1;
};
enum class event_status_register_bitmask : scpi::register_8bit_type {
  operation_complete = (1UL << 0),
  request_control = (1UL << 1),
  query_error = (1UL << 2),
  device_dependent_error = (1UL << 3),
  execution_error = (1UL << 4),
  command_error = (1UL << 5),
  user_request = (1UL << 6),
  power_on = (1UL << 7),
  all_bits = (operation_complete | request_control | query_error |
              device_dependent_error | execution_error | command_error |
              user_request | power_on)
};
struct event_status_register_bits {
  bool operation_complete : 1;
  bool request_control : 1;
  bool query_error : 1;
  bool device_dependent_error : 1;
  bool execution_error : 1;
  bool command_error : 1;
  bool user_request : 1;
  bool power_on : 1;
};
}  // namespace detail

using event_status_register =
    scpi::register_8bit_abstract<detail::event_status_register_bitmask,
                                 detail::event_status_register_bits>;

using status_byte_register =
    scpi::register_8bit_abstract<detail::status_byte_register_bitmask,
                                 detail::status_byte_register_bits>;
}  // namespace ieee488
}  // namespace scpi
