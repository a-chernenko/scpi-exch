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

#include <stdexcept>

#include "ieee488_mnemonics.h"

using namespace scpi::ieee488;

namespace scpi::ieee488 {
struct command_program_header {
  static constexpr auto AAD = "*AAD";
  static constexpr auto DLF = "*DLF";
  static constexpr auto PUD = "*PUD";
  static constexpr auto RDT = "*RDT";
  static constexpr auto RST = "*RST";
  static constexpr auto OPC = "*OPC";
  static constexpr auto WAI = "*WAI";
  static constexpr auto DMC = "*DMC";
  static constexpr auto EMC = "*EMC";
  static constexpr auto PMC = "*PMC";
  static constexpr auto RMC = "*RMC";
  static constexpr auto PRE = "*PRE";
  static constexpr auto CLS = "*CLS";
  static constexpr auto ESE = "*ESE";
  static constexpr auto PSC = "*PSC";
  static constexpr auto SRE = "*SRE";
  static constexpr auto DDT = "*DDT";
  static constexpr auto TRG = "*TRG";
  static constexpr auto PCB = "*PCB";
  static constexpr auto RCL = "*RCL";
  static constexpr auto SAV = "*SAV";
  static constexpr auto SDS = "*SDS";
  command_program_header() = delete;
};

struct query_program_header {
  static constexpr auto IDN = "*IDN?";
  static constexpr auto OPT = "*OPT?";
  static constexpr auto PUD = "*PUD?";
  static constexpr auto RDT = "*RDT?";
  static constexpr auto CAL = "*CAL?";
  static constexpr auto LRN = "*LRN?";
  static constexpr auto TST = "*TST?";
  static constexpr auto OPC = "*OPC?";
  static constexpr auto EMC = "*EMC?";
  static constexpr auto GMC = "*GMC?";
  static constexpr auto LMC = "*LMC?";
  static constexpr auto IST = "*IST?";
  static constexpr auto PRE = "*PRE?";
  static constexpr auto ESE = "*ESE?";
  static constexpr auto ESR = "*ESR?";
  static constexpr auto PSC = "*PSC?";
  static constexpr auto SRE = "*SRE?";
  static constexpr auto STB = "*STB?";
  static constexpr auto DDT = "*DDT?";
  query_program_header() = delete;
};

}  // namespace scpi::ieee488

mnemonics::mnemonic_type mnemonics::get(const common_query &query) {
  switch (query) {
    case common_query::IDN_identification:
      return query_program_header::IDN;
    case common_query::OPT_option_identification:
      return query_program_header::OPT;
    case common_query::PUD_protected_user_data:
      return query_program_header::PUD;
    case common_query::RDT_resource_description_transfer:
      return query_program_header::RDT;
    case common_query::CAL_calibration:
      return query_program_header::CAL;
    case common_query::LRN_learn_device_setup:
      return query_program_header::LRN;
    case common_query::TST_self_test:
      return query_program_header::TST;
    case common_query::OPCQ_operation_complete:
      return query_program_header::OPC;
    case common_query::EMC_enable_macro:
      return query_program_header::EMC;
    case common_query::GMC_get_macro_contents:
      return query_program_header::GMC;
    case common_query::LMC_learn_macro:
      return query_program_header::LMC;
    case common_query::IST_individual_status:
      return query_program_header::IST;
    case common_query::PREQ_parallel_poll_enable_register:
      return query_program_header::PRE;
    case common_query::ESE_standard_event_status_enable:
      return query_program_header::ESE;
    case common_query::ESR_standard_event_status_register:
      return query_program_header::ESR;
    case common_query::PSC_power_on_status_clear:
      return query_program_header::PSC;
    case common_query::SRE_service_request_enable:
      return query_program_header::SRE;
    case common_query::STB_read_status_byte:
      return query_program_header::STB;
    case common_query::DDTQ_define_device_trigger:
      return query_program_header::DDT;
    default:
      throw std::invalid_argument("get invalid argument");
  }
}

mnemonics::mnemonic_type mnemonics::get(const common_command &command) {
  switch (command) {
    case common_command::AAD_accept_address:
      return command_program_header::AAD;
    case common_command::DLF_disable_listener_function:
      return command_program_header::DLF;
    case common_command::PUD_protected_user_data:
      return command_program_header::PUD;
    case common_command::RDT_resource_description_transfer:
      return command_program_header::RDT;
    case common_command::RST_reset:
      return command_program_header::RST;
    case common_command::OPC_operation_complete:
      return command_program_header::OPC;
    case common_command::WAI_wait_to_continue:
      return command_program_header::WAI;
    case common_command::DMC_define_macro:
      return command_program_header::DMC;
    case common_command::EMC_enable_macro:
      return command_program_header::EMC;
    case common_command::PMC_purge_macro:
      return command_program_header::PMC;
    case common_command::RMC_remove_individual_macro:
      return command_program_header::RMC;
    case common_command::PRE_parallel_poll_enable_register:
      return command_program_header::PRE;
    case common_command::CLS_clear_status:
      return command_program_header::CLS;
    case common_command::ESE_standard_event_status_enable:
      return command_program_header::ESE;
    case common_command::PSC_power_on_status_clear:
      return command_program_header::PSC;
    case common_command::SRE_service_request_enable:
      return command_program_header::SRE;
    case common_command::DDT_define_device_trigger:
      return command_program_header::DDT;
    case common_command::TRG_trigger:
      return command_program_header::TRG;
    case common_command::PCB_pass_control_back:
      return command_program_header::PCB;
    case common_command::RCL_recall:
      return command_program_header::RCL;
    case common_command::SAV_save:
      return command_program_header::SAV;
    case common_command::SDS_save_default_device_setting:
      return command_program_header::SDS;
    default:
      throw std::invalid_argument("get invalid argument");
  }
}
