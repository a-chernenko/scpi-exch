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

#ifndef IEEE4882_MNEMONICS_H
#define IEEE4882_MNEMONICS_H

// IEEE Std 488.2-1992

namespace Ieee4882Mnemonics {
/* IEEE 488.2 Common Command Groups */
enum class CommonQueryType : unsigned int {
  /* System Data */
  IDN_IdentificationQuery,               // Clause 10.14 (IEEE Std 488.2-1992)
  OPT_OptionIdentificationQuery,         // Clause 10.20 (IEEE Std 488.2-1992)
  PUD_ProtectedUserDataQuery,            // Clause 10.28 (IEEE Std 488.2-1992)
  RDT_ResourceDescriptionTransferQuery,  // Clause 10.31 (IEEE Std 488.2-1992)
  /* Internal Operations */
  CAL_CalibrationQuery,       // Clause 10.2 (IEEE Std 488.2-1992)
  LRN_LearnDeviceSetupQuery,  // Clause 10.17 (IEEE Std 488.2-1992)
  TST_SelfTestQuery,          // Clause 10.38 (IEEE Std 488.2-1992)
  /* Synchronization */
  OPCQ_OperationCompleteQuery,
  /* Macro */
  EMC_EnableMacroQuery,
  GMC_GetMacroContentsQuery,
  LMC_LearnMacroQuery,
  /* Parallel Poll */
  IST_IndividualStatusQuery,
  PREQ_ParallelPollEnableRegisterQuery,
  /* Status & Event */
  ESE_StandardEventStatusEnableQuery,
  ESR_StandardEventStatusRegisterQuery,
  PSC_PowerOnStatusClearQuery,
  SRE_ServiceRequestEnableQuery,
  STB_ReadStatusByteQuery,
  /* Trigger */
  DDTQ_DefineDeviceTriggerQuery
};

/* IEEE 488.2 Common Command Groups */
enum class CommonCommandType : unsigned int {
  /* Auto Configure */
  AAD_AcceptAddressCommand,
  DLF_DisableListenerFunctionCommand,
  /* System Data */
  PUD_ProtectedUserDataCommand,
  RDT_ResourceDescriptionTransferCommand,
  /* Internal Operations */
  RST_ResetCommand,
  /* Synchronization */
  OPC_OperationCompleteCommand,
  WAI_WaitToContinueCommand,
  /* Macro */
  DMC_DefineMacroCommand,
  EMC_EnableMacroCommand,
  PMC_PurgeMacrosCommand,
  /* Macro Extended */
  RMC_RemoveIndividualMacroCommand,
  /* Parallel Poll */
  PRE_ParallelPollEnableRegisterCommand,
  /* Status & Event */
  CLS_ClearStatusCommand,
  ESE_StandardEventStatusEnableCommand,
  PSC_PowerOnStatusClearCommand,
  SRE_ServiceRequestEnableCommand,
  /* Trigger */
  DDT_DefineDeviceTriggerCommand,
  TRG_TriggerCommand,
  /* Controller */
  PCB_PassControlBackCommand,
  /* Stored Settings */
  RCL_RecallCommand,
  SAV_SaveCommand,
  /* Stored Setting Extended */
  SDS_SaveDefaultDeviceSettingCommand
};

class CIeee4882Mnemonics {
 protected:
  using MnemonicType = const char*;
  static MnemonicType GetCommonQueryMnemonic(const CommonQueryType&);
  static MnemonicType GetCommonCommandMnemonic(const CommonCommandType&);
  CIeee4882Mnemonics() = default;
};
}  // namespace Ieee4882Mnemonics

#endif  // IEEE4882_MNEMONICS_H
