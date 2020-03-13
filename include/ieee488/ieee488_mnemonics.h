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

// IEEE Std 488.2-1992

namespace scpi {
namespace ieee488 {
/* IEEE 488.2 Common Command Groups */
enum class common_query : unsigned int {
  /* System data */
  IDN_identification,                 // Clause 10.14 (IEEE Std 488.2-1992)
  OPT_option_identification,          // Clause 10.20 (IEEE Std 488.2-1992)
  PUD_protected_user_data,            // Clause 10.28 (IEEE Std 488.2-1992)
  RDT_resource_description_transfer,  // Clause 10.31 (IEEE Std 488.2-1992)
  /* Internal Operations */
  CAL_calibration,         // Clause 10.2 (IEEE Std 488.2-1992)
  LRN_learn_device_setup,  // Clause 10.17 (IEEE Std 488.2-1992)
  TST_self_test,           // Clause 10.38 (IEEE Std 488.2-1992)
  /* Synchronization */
  OPCQ_operation_complete,
  /* Macro */
  EMC_enable_macro,
  GMC_get_macro_contents,
  LMC_learn_macro,
  /* Parallel Poll */
  IST_individual_status,
  PREQ_parallel_poll_enable_register,
  /* Status & Event */
  ESE_standard_event_status_enable,
  ESR_standard_event_status_register,
  PSC_power_on_status_clear,
  SRE_service_request_enable,
  STB_read_status_byte,
  /* Trigger */
  DDTQ_define_device_trigger
};

/* IEEE 488.2 Common Command Groups */
enum class common_command : unsigned int {
  /* Auto Configure */
  AAD_accept_address,
  DLF_disable_listener_function,
  /* System data */
  PUD_protected_user_data,
  RDT_resource_description_transfer,
  /* Internal Operations */
  RST_reset,
  /* Synchronization */
  OPC_operation_complete,
  WAI_wait_to_continue,
  /* Macro */
  DMC_define_macro,
  EMC_enable_macro,
  PMC_purge_macro,
  /* Macro Extended */
  RMC_remove_individual_macro,
  /* Parallel Poll */
  PRE_parallel_poll_enable_register,
  /* Status & Event */
  CLS_clear_status,
  ESE_standard_event_status_enable,
  PSC_power_on_status_clear,
  SRE_service_request_enable,
  /* Trigger */
  DDT_define_device_trigger,
  TRG_trigger,
  /* Controller */
  PCB_pass_control_back,
  /* Stored Settings */
  RCL_recall,
  SAV_save,
  /* Stored Setting Extended */
  SDS_save_default_device_setting
};

class mnemonics {
 protected:
  using mnemonic_type = const char*;
  static mnemonic_type get(const common_query&);
  static mnemonic_type get(const common_command&);
  mnemonics() = default;
};
}  // namespace ieee488
}  // namespace scpi
