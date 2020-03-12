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

#include "ieee4882_mnemonics.h"
#include <stdexcept>


using namespace Ieee4882Mnemonics;

struct CommandProgramHeader {
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
  CommandProgramHeader() = delete;
};

struct QueryProgramHeader {
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
  QueryProgramHeader() = delete;
};

CIeee4882Mnemonics::MnemonicType CIeee4882Mnemonics::GetCommonQueryMnemonic(
    const CommonQueryType &query) {
  switch (query) {
    case CommonQueryType::IDN_IdentificationQuery:
      return QueryProgramHeader::IDN;
    case CommonQueryType::OPT_OptionIdentificationQuery:
      return QueryProgramHeader::OPT;
    case CommonQueryType::PUD_ProtectedUserDataQuery:
      return QueryProgramHeader::PUD;
    case CommonQueryType::RDT_ResourceDescriptionTransferQuery:
      return QueryProgramHeader::RDT;
    case CommonQueryType::CAL_CalibrationQuery:
      return QueryProgramHeader::CAL;
    case CommonQueryType::LRN_LearnDeviceSetupQuery:
      return QueryProgramHeader::LRN;
    case CommonQueryType::TST_SelfTestQuery:
      return QueryProgramHeader::TST;
    case CommonQueryType::OPCQ_OperationCompleteQuery:
      return QueryProgramHeader::OPC;
    case CommonQueryType::EMC_EnableMacroQuery:
      return QueryProgramHeader::EMC;
    case CommonQueryType::GMC_GetMacroContentsQuery:
      return QueryProgramHeader::GMC;
    case CommonQueryType::LMC_LearnMacroQuery:
      return QueryProgramHeader::LMC;
    case CommonQueryType::IST_IndividualStatusQuery:
      return QueryProgramHeader::IST;
    case CommonQueryType::PREQ_ParallelPollEnableRegisterQuery:
      return QueryProgramHeader::PRE;
    case CommonQueryType::ESE_StandardEventStatusEnableQuery:
      return QueryProgramHeader::ESE;
    case CommonQueryType::ESR_StandardEventStatusRegisterQuery:
      return QueryProgramHeader::ESR;
    case CommonQueryType::PSC_PowerOnStatusClearQuery:
      return QueryProgramHeader::PSC;
    case CommonQueryType::SRE_ServiceRequestEnableQuery:
      return QueryProgramHeader::SRE;
    case CommonQueryType::STB_ReadStatusByteQuery:
      return QueryProgramHeader::STB;
    case CommonQueryType::DDTQ_DefineDeviceTriggerQuery:
      return QueryProgramHeader::DDT;
    default:
      throw std::invalid_argument("GetCommonQueryMnemonic invalid argument");
  }
}

CIeee4882Mnemonics::MnemonicType CIeee4882Mnemonics::GetCommonCommandMnemonic(
    const CommonCommandType &command) {
  switch (command) {
    case CommonCommandType::AAD_AcceptAddressCommand:
      return CommandProgramHeader::AAD;
    case CommonCommandType::DLF_DisableListenerFunctionCommand:
      return CommandProgramHeader::DLF;
    case CommonCommandType::PUD_ProtectedUserDataCommand:
      return CommandProgramHeader::PUD;
    case CommonCommandType::RDT_ResourceDescriptionTransferCommand:
      return CommandProgramHeader::RDT;
    case CommonCommandType::RST_ResetCommand:
      return CommandProgramHeader::RST;
    case CommonCommandType::OPC_OperationCompleteCommand:
      return CommandProgramHeader::OPC;
    case CommonCommandType::WAI_WaitToContinueCommand:
      return CommandProgramHeader::WAI;
    case CommonCommandType::DMC_DefineMacroCommand:
      return CommandProgramHeader::DMC;
    case CommonCommandType::EMC_EnableMacroCommand:
      return CommandProgramHeader::EMC;
    case CommonCommandType::PMC_PurgeMacrosCommand:
      return CommandProgramHeader::PMC;
    case CommonCommandType::RMC_RemoveIndividualMacroCommand:
      return CommandProgramHeader::RMC;
    case CommonCommandType::PRE_ParallelPollEnableRegisterCommand:
      return CommandProgramHeader::PRE;
    case CommonCommandType::CLS_ClearStatusCommand:
      return CommandProgramHeader::CLS;
    case CommonCommandType::ESE_StandardEventStatusEnableCommand:
      return CommandProgramHeader::ESE;
    case CommonCommandType::PSC_PowerOnStatusClearCommand:
      return CommandProgramHeader::PSC;
    case CommonCommandType::SRE_ServiceRequestEnableCommand:
      return CommandProgramHeader::SRE;
    case CommonCommandType::DDT_DefineDeviceTriggerCommand:
      return CommandProgramHeader::DDT;
    case CommonCommandType::TRG_TriggerCommand:
      return CommandProgramHeader::TRG;
    case CommonCommandType::PCB_PassControlBackCommand:
      return CommandProgramHeader::PCB;
    case CommonCommandType::RCL_RecallCommand:
      return CommandProgramHeader::RCL;
    case CommonCommandType::SAV_SaveCommand:
      return CommandProgramHeader::SAV;
    case CommonCommandType::SDS_SaveDefaultDeviceSettingCommand:
      return CommandProgramHeader::SDS;
    default:
      throw std::invalid_argument("GetCommonCommandMnemonic invalid argument");
  }
}
