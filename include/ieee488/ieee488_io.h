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

#include <mutex>

#include "io.h"

#include "ieee488_constants.h"
#include "ieee488_mnemonics.h"
#include "ieee488_registers_type.h"

#include "scpi_export.h"

namespace scpi {
class SCPI_API ieee488_io final : ieee488::mnemonics, ieee488::constants {
 public:
  ieee488_io(const scpi::io &);
  ieee488::status_byte_register get_status_byte_register() const;
  void set_service_request_enable(const ieee488::status_byte_register &) const;
  ieee488::status_byte_register get_service_request_enable() const;
  void set_event_status_enable(const ieee488::event_status_register &) const;
  ieee488::event_status_register get_event_status_enable() const;
  ieee488::event_status_register get_event_status_register() const;
  int self_test(std::string &) const;
  void get_identification(std::string &) const;
  void reset() const;
  void wait_to_continue() const;
  void clear_status() const;
  void set_operation_complete() const;
  void wait_operation_complete(
      const unsigned int timeouts_ms = query_timeout_ms) const;
  void error_handler() const;
  bool get_error_handler_enabled() const noexcept;
  void set_error_handler_enabled(const bool value = true) noexcept;

  ieee488_io() = delete;
  ieee488_io(const ieee488_io &) = delete;
  ieee488_io &operator=(const ieee488_io &) = delete;

 private:
  static std::recursive_mutex _mutex;
  bool _error_handler_enabled{};
  const scpi::io &io;
  void command(const scpi::ieee488::common_command &) const;
  template <typename TypeValue>
  void command(const scpi::ieee488::common_command &, const TypeValue &) const;
  void query(const scpi::ieee488::common_query &, std::string &,
             const unsigned int) const;
};
}  // namespace scpi
