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

#include "ieee488_io.h"
#include "io_error.h"
#include "scpi_error.h"

using namespace scpi;
using namespace ieee488;

std::recursive_mutex ieee488_io::_mutex;

ieee488_io::ieee488_io(const scpi::io &scpiHardware) : io(scpiHardware) {}

void ieee488_io::command(const ieee488::common_command &command) const {
  std::lock_guard<std::recursive_mutex> lock{_mutex};
  const std::string request = get(command);
  io.write(request);
  error_handler();
}

template <typename TypeValue>
void ieee488_io::command(const ieee488::common_command &command,
                         const TypeValue &value) const {
  std::lock_guard<std::recursive_mutex> lock{_mutex};
  const std::string request =
      get(command) + std::string{" "} + std::to_string(value);
  io.write(request);
  error_handler();
}

void ieee488_io::query(
    const ieee488::common_query &query, std::string &response,
    const unsigned int timeouts_ms = query_timeout_ms) const {
  std::lock_guard<std::recursive_mutex> lock{_mutex};
  const std::string request = get(query);
  io.write(request);
  bool read_timeout{};
  try {
    io.read(response, timeouts_ms);
  } catch (scpi::read_timeout) {
    read_timeout = true;
  }
  if (query != ieee488::common_query::STB_read_status_byte) error_handler();
  if (read_timeout) throw scpi::read_timeout();
}

status_byte_register ieee488_io::get_status_byte_register() const {
  std::string response;
  query(ieee488::common_query::STB_read_status_byte, response);
  return status_byte_register{response};
}

void ieee488_io::set_service_request_enable(
    const status_byte_register &value) const {
  const auto reg = value.get_register();
  command(ieee488::common_command::SRE_service_request_enable, reg);
}

status_byte_register ieee488_io::get_service_request_enable() const {
  std::string response;
  query(ieee488::common_query::SRE_service_request_enable, response);
  return status_byte_register{response};
}

void ieee488_io::set_event_status_enable(
    const event_status_register &value) const {
  const auto reg = value.get_register();
  command(ieee488::common_command::ESE_standard_event_status_enable, reg);
}

event_status_register ieee488_io::get_event_status_enable() const {
  std::string response;
  query(ieee488::common_query::ESE_standard_event_status_enable, response);
  return event_status_register{response};
}

event_status_register ieee488_io::get_event_status_register() const {
  std::string response;
  query(ieee488::common_query::ESR_standard_event_status_register, response);
  return event_status_register{response};
}

int ieee488_io::self_test(std::string &_message) const {
  std::string response;
  query(ieee488::common_query::TST_self_test, response, self_test_timeout_ms);
  std::string::size_type offset{};
  auto result = std::stoi(response, &offset);
  if (result != 0) _message = response.substr(offset);
  return result;
}

void ieee488_io::get_identification(std::string &idn) const {
  query(ieee488::common_query::IDN_identification, idn);
}

void ieee488_io::reset() const { command(ieee488::common_command::RST_reset); }

void ieee488_io::wait_to_continue() const {
  command(ieee488::common_command::WAI_wait_to_continue);
}

void ieee488_io::clear_status() const {
  command(ieee488::common_command::CLS_clear_status);
}

void ieee488_io::set_operation_complete() const {
  command(ieee488::common_command::OPC_operation_complete);
}

void ieee488_io::wait_operation_complete(const unsigned int timeouts_ms) const {
  std::string response;
  query(ieee488::common_query::OPCQ_operation_complete, response, timeouts_ms);
}

void ieee488_io::error_handler() const {
  if (!_error_handler_enabled) return;
  const auto status_byte = get_status_byte_register();
  if (status_byte.data.bits.standard_event_status_register) {
    const auto event_status_register = get_event_status_register();
    if (event_status_register.data.bits.command_error)
      throw command_error();
    else if (event_status_register.data.bits.query_error)
      throw query_error();
    else if (event_status_register.data.bits.execution_error)
      throw execution_error();
    else if (event_status_register.data.bits.device_dependent_error)
      throw device_dependent_error();
  }
}

bool ieee488_io::get_error_handler_enabled() const noexcept {
  return _error_handler_enabled;
}
void ieee488_io::set_error_handler_enabled(const bool value) noexcept {
  _error_handler_enabled = value;
}
