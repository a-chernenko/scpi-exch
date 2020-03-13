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

#include <type_traits>

#include "const_string.h"
#include "scpi_export.h"

// SCPI-1999.0

#define ADD_MNEMONIC_DEFINITION(PARAMETR, MNEMONIC)          \
  static constexpr const_string<sizeof(MNEMONIC)> PARAMETR { \
    MAKE_CONST_STRING_FROM_LITERAL_STRING(MNEMONIC)          \
  }

namespace scpi::mnemonics {
struct SCPI_API CMnemonics final {
  ADD_MNEMONIC_DEFINITION(ABORt, "ABOR");
  ADD_MNEMONIC_DEFINITION(ALL, "ALL");
  ADD_MNEMONIC_DEFINITION(AC, "AC");
  ADD_MNEMONIC_DEFINITION(ACQuire, "ACQ");
  ADD_MNEMONIC_DEFINITION(AVERage, "AVER");
  ADD_MNEMONIC_DEFINITION(AMPLitude, "AMPL");
  ADD_MNEMONIC_DEFINITION(AOFF, "AOFF");
  ADD_MNEMONIC_DEFINITION(APPLy, "APPL");
  ADD_MNEMONIC_DEFINITION(ATTenuation, "ATT");
  ADD_MNEMONIC_DEFINITION(AUTO, "AUTO");
  ADD_MNEMONIC_DEFINITION(AUToscale, "AUT");
  ADD_MNEMONIC_DEFINITION(BANDwidth, "BAND");
  ADD_MNEMONIC_DEFINITION(CALibration, "CAL");
  ADD_MNEMONIC_DEFINITION(CENTer, "CENT");
  ADD_MNEMONIC_DEFINITION(CLEar, "CLE");
  ADD_MNEMONIC_DEFINITION(CHANnel, "CHAN");
  ADD_MNEMONIC_DEFINITION(COUPling, "COUP");
  ADD_MNEMONIC_DEFINITION(COMMA, ",");
  ADD_MNEMONIC_DEFINITION(COLON, ":");
  ADD_MNEMONIC_DEFINITION(CONDition, "COND");
  ADD_MNEMONIC_DEFINITION(CONFigure, "CONF");
  ADD_MNEMONIC_DEFINITION(COUNt, "COUN");
  ADD_MNEMONIC_DEFINITION(CURRent, "CURR");
  ADD_MNEMONIC_DEFINITION(DEFault, "DEF");
  ADD_MNEMONIC_DEFINITION(DC, "DC");
  ADD_MNEMONIC_DEFINITION(DISPlay, "DISP");
  ADD_MNEMONIC_DEFINITION(ENABle, "ENAB");
  ADD_MNEMONIC_DEFINITION(ERRor, "ERR");
  ADD_MNEMONIC_DEFINITION(EVENT, "EVENT");
  ADD_MNEMONIC_DEFINITION(FETCh, "FETC");
  ADD_MNEMONIC_DEFINITION(FIXed, "FIX");
  ADD_MNEMONIC_DEFINITION(FIFTy, "FIFT");
  ADD_MNEMONIC_DEFINITION(FREQuency, "FREQ");
  ADD_MNEMONIC_DEFINITION(FRESistance, "FRES");
  ADD_MNEMONIC_DEFINITION(HRESolution, "HRES");
  ADD_MNEMONIC_DEFINITION(IMMediate, "IMM");
  ADD_MNEMONIC_DEFINITION(IMPedance, "IMP");
  ADD_MNEMONIC_DEFINITION(INITiate, "INIT");
  ADD_MNEMONIC_DEFINITION(INPut, "INP");
  ADD_MNEMONIC_DEFINITION(INTegrity, "INT");
  ADD_MNEMONIC_DEFINITION(LEVel, "LEV");
  ADD_MNEMONIC_DEFINITION(LOCK, "LOCK");
  ADD_MNEMONIC_DEFINITION(MARKer, "MARK");
  ADD_MNEMONIC_DEFINITION(MAXimum, "MAX");
  ADD_MNEMONIC_DEFINITION(MAXHold, "MAXH");
  ADD_MNEMONIC_DEFINITION(MINHold, "MINH");
  ADD_MNEMONIC_DEFINITION(MEASure, "MEAS");
  ADD_MNEMONIC_DEFINITION(MINimum, "MIN");
  ADD_MNEMONIC_DEFINITION(MODulation, "MOD");
  ADD_MNEMONIC_DEFINITION(MODE, "MODE");
  ADD_MNEMONIC_DEFINITION(NEXT, "NEXT");
  ADD_MNEMONIC_DEFINITION(NORMal, "NORM");
  ADD_MNEMONIC_DEFINITION(OFFSet, "OFFS");
  ADD_MNEMONIC_DEFINITION(OPERation, "OPER");
  ADD_MNEMONIC_DEFINITION(ONEMeg, "ONEM");
  ADD_MNEMONIC_DEFINITION(OUTPut, "OUTP");
  ADD_MNEMONIC_DEFINITION(PEAK, "PEAK");
  ADD_MNEMONIC_DEFINITION(PHASe, "PHAS");
  ADD_MNEMONIC_DEFINITION(POINt, "POIN");
  ADD_MNEMONIC_DEFINITION(POINts, "POIN");
  ADD_MNEMONIC_DEFINITION(POWer, "POW");
  ADD_MNEMONIC_DEFINITION(PROTection, "PROT");
  ADD_MNEMONIC_DEFINITION(PROBe, "PROB");
  ADD_MNEMONIC_DEFINITION(POSitive, "POS");
  ADD_MNEMONIC_DEFINITION(NEGative, "NEG");
  ADD_MNEMONIC_DEFINITION(EITHer, "EITH");
  ADD_MNEMONIC_DEFINITION(QUERY, "?");
  ADD_MNEMONIC_DEFINITION(QUEStionable, "QUES");
  ADD_MNEMONIC_DEFINITION(RANGe, "RANG");
  ADD_MNEMONIC_DEFINITION(READ, "READ");
  ADD_MNEMONIC_DEFINITION(REFerence, "REF");
  ADD_MNEMONIC_DEFINITION(RELease, "REL");
  ADD_MNEMONIC_DEFINITION(RESistance, "RES");
  ADD_MNEMONIC_DEFINITION(RESolution, "RES");
  ADD_MNEMONIC_DEFINITION(SCALar, "SCAL");
  ADD_MNEMONIC_DEFINITION(SEQuence, "SEQ");
  ADD_MNEMONIC_DEFINITION(SEMICOLON, ";");
  ADD_MNEMONIC_DEFINITION(SOURce, "SOUR");
  ADD_MNEMONIC_DEFINITION(SPACE, " ");
  ADD_MNEMONIC_DEFINITION(SPAN, "SPAN");
  ADD_MNEMONIC_DEFINITION(STARt, "STAR");
  ADD_MNEMONIC_DEFINITION(STATe, "STAT");
  ADD_MNEMONIC_DEFINITION(STATus, "STAT");
  ADD_MNEMONIC_DEFINITION(STEP, "STEP");
  ADD_MNEMONIC_DEFINITION(STOP, "STOP");
  ADD_MNEMONIC_DEFINITION(SLOPe, "SLOP");
  ADD_MNEMONIC_DEFINITION(SWEep, "SWE");
  ADD_MNEMONIC_DEFINITION(SYSTem, "SYST");
  ADD_MNEMONIC_DEFINITION(TCouple, "TC");
  ADD_MNEMONIC_DEFINITION(TRACe, "TRAC");
  ADD_MNEMONIC_DEFINITION(TEMPerature, "TEMP");
  ADD_MNEMONIC_DEFINITION(THERmistor, "THER");
  ADD_MNEMONIC_DEFINITION(FTHermistor, "FTH");
  ADD_MNEMONIC_DEFINITION(TYPE, "TYPE");
  ADD_MNEMONIC_DEFINITION(RTD, "RTD");
  ADD_MNEMONIC_DEFINITION(FRTD, "FRTD");
  ADD_MNEMONIC_DEFINITION(TIME, "TIME");
  ADD_MNEMONIC_DEFINITION(TIMe, "TIM");
  ADD_MNEMONIC_DEFINITION(TRIGger, "TRIG");
  ADD_MNEMONIC_DEFINITION(TRIPped, "TRIP");
  ADD_MNEMONIC_DEFINITION(UNIT, "UNIT");
  ADD_MNEMONIC_DEFINITION(VIDeo, "VID");
  ADD_MNEMONIC_DEFINITION(VOLTage, "VOLT");
  ADD_MNEMONIC_DEFINITION(WRITe, "WRIT");
  CMnemonics() = delete;
};

template <std::size_t M, std::size_t N>
std::string MakeMnemonicNumberedString(const const_string<M> &topsubsystem,
                                       const unsigned int index,
                                       const const_string<N> &subsystem) {
  std::string tmp{topsubsystem.to_string()};
  tmp += std::to_string(index);
  tmp += CMnemonics::COLON.to_string();
  tmp += subsystem.to_string();
  return tmp;
};

template <std::size_t N>
std::string MakeMnemonicNumberedString(const const_string<N> &mnemonic,
                                       const unsigned int index) {
  std::string tmp{mnemonic.to_string()};
  tmp += std::to_string(index);
  return tmp;
};

template <std::size_t N, const const_string<N> &mnemonic, unsigned int num>
struct CMnemonicNumbered {
  using type = const_string<
      N + sizeof(typename const_string_from_integer<unsigned, num>::type) - 1>;
  static constexpr type Mnemonic{
      mnemonic + const_string_from_integer<unsigned, num>::value};
};
template <std::size_t N, const const_string<N> &mnemonic, unsigned int num>
constexpr typename CMnemonicNumbered<N, mnemonic, num>::type
    CMnemonicNumbered<N, mnemonic, num>::Mnemonic;

template <std::size_t N, const const_string<N> &topsubsystem>
struct CTopSubsystemMnemonic {
  using type = const_string<N>;
  static constexpr type Mnemonic{topsubsystem};
};
template <std::size_t N, const const_string<N> &topsubsystem>
constexpr typename CTopSubsystemMnemonic<N, topsubsystem>::type
    CTopSubsystemMnemonic<N, topsubsystem>::Mnemonic;

template <std::size_t N, const const_string<N> &topsubsystem>
struct CTopSubsystemCommandMnemonic {
  using type = const_string<N + CMnemonics::SPACE.length()>;
  static constexpr type CommandMnemonic{topsubsystem + CMnemonics::SPACE};
};
template <std::size_t N, const const_string<N> &topsubsystem>
constexpr typename CTopSubsystemCommandMnemonic<N, topsubsystem>::type
    CTopSubsystemCommandMnemonic<N, topsubsystem>::CommandMnemonic;

template <std::size_t N, const const_string<N> &topsubsystem>
struct CTopSubsystemQueryMnemonic {
  using type = const_string<N + CMnemonics::QUERY.length()>;
  static constexpr type QueryMnemonic{topsubsystem + CMnemonics::QUERY};
};
template <std::size_t N, const const_string<N> &topsubsystem>
constexpr typename CTopSubsystemQueryMnemonic<N, topsubsystem>::type
    CTopSubsystemQueryMnemonic<N, topsubsystem>::QueryMnemonic;

template <std::size_t N, const const_string<N> &topsubsystem>
struct CTopSubsystemQueryMaximumMnemonic {
  using type =
      const_string<N + CMnemonics::QUERY.length() + CMnemonics::SPACE.length() +
                   CMnemonics::MAXimum.length()>;
  static constexpr type QueryMaximumMnemonic{topsubsystem + CMnemonics::QUERY +
                                             CMnemonics::SPACE +
                                             CMnemonics::MAXimum};
};
template <std::size_t N, const const_string<N> &topsubsystem>
constexpr typename CTopSubsystemQueryMaximumMnemonic<N, topsubsystem>::type
    CTopSubsystemQueryMaximumMnemonic<N, topsubsystem>::QueryMaximumMnemonic;

template <std::size_t N, const const_string<N> &topsubsystem>
struct CTopSubsystemQueryMinimumMnemonic {
  using type =
      const_string<N + CMnemonics::QUERY.length() + CMnemonics::SPACE.length() +
                   CMnemonics::MINimum.length()>;
  static constexpr type QueryMinimumMnemonic{topsubsystem + CMnemonics::QUERY +
                                             CMnemonics::SPACE +
                                             CMnemonics::MINimum};
};
template <std::size_t N, const const_string<N> &topsubsystem>
constexpr typename CTopSubsystemQueryMinimumMnemonic<N, topsubsystem>::type
    CTopSubsystemQueryMinimumMnemonic<N, topsubsystem>::QueryMinimumMnemonic;

template <std::size_t N, const const_string<N> &topsubsystem>
struct CTopSubsystemQueryDefaultMnemonic {
  using type =
      const_string<N + CMnemonics::QUERY.length() + CMnemonics::SPACE.length() +
                   CMnemonics::DEFault.length()>;
  static constexpr type QueryDefaultMnemonic{topsubsystem + CMnemonics::QUERY +
                                             CMnemonics::SPACE +
                                             CMnemonics::DEFault};
};
template <std::size_t N, const const_string<N> &topsubsystem>
constexpr typename CTopSubsystemQueryDefaultMnemonic<N, topsubsystem>::type
    CTopSubsystemQueryDefaultMnemonic<N, topsubsystem>::QueryDefaultMnemonic;

template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
struct CSubsystemMnemonic {
  using type = const_string<M + N - 1 + CMnemonics::COLON.length()>;
  static constexpr type Mnemonic{topsubsystem + CMnemonics::COLON + subsystem};
};
template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
constexpr typename CSubsystemMnemonic<M, topsubsystem, N, subsystem>::type
    CSubsystemMnemonic<M, topsubsystem, N, subsystem>::Mnemonic;

template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
struct CSubsystemCommandMnemonic {
  using type = const_string<M + N - 1 + CMnemonics::COLON.length() +
                            CMnemonics::SPACE.length()>;
  static constexpr type CommandMnemonic{topsubsystem + CMnemonics::COLON +
                                        subsystem + CMnemonics::SPACE};
};
template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
constexpr typename CSubsystemCommandMnemonic<M, topsubsystem, N,
                                             subsystem>::type
    CSubsystemCommandMnemonic<M, topsubsystem, N, subsystem>::CommandMnemonic;

template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
struct CSubsystemQueryMnemonic {
  using type = const_string<M + N - 1 + CMnemonics::COLON.length() +
                            CMnemonics::QUERY.length()>;
  static constexpr type QueryMnemonic{topsubsystem + CMnemonics::COLON +
                                      subsystem + CMnemonics::QUERY};
};
template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
constexpr typename CSubsystemQueryMnemonic<M, topsubsystem, N, subsystem>::type
    CSubsystemQueryMnemonic<M, topsubsystem, N, subsystem>::QueryMnemonic;

template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
struct CSubsystemQueryMaximumMnemonic {
  using type =
      const_string<M + N - 1 + CMnemonics::COLON.length() +
                   CMnemonics::QUERY.length() + CMnemonics::SPACE.length() +
                   CMnemonics::MAXimum.length()>;
  static constexpr type QueryMaximumMnemonic{
      topsubsystem + CMnemonics::COLON + subsystem + CMnemonics::QUERY +
      CMnemonics::SPACE + CMnemonics::MAXimum};
};
template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
constexpr
    typename CSubsystemQueryMaximumMnemonic<M, topsubsystem, N, subsystem>::type
        CSubsystemQueryMaximumMnemonic<M, topsubsystem, N,
                                       subsystem>::QueryMaximumMnemonic;

template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
struct CSubsystemQueryMinimumMnemonic {
  using type =
      const_string<M + N - 1 + CMnemonics::COLON.length() +
                   CMnemonics::QUERY.length() + CMnemonics::SPACE.length() +
                   CMnemonics::MINimum.length()>;
  static constexpr type QueryMinimumMnemonic{
      topsubsystem + CMnemonics::COLON + subsystem + CMnemonics::QUERY +
      CMnemonics::SPACE + CMnemonics::MINimum};
};
template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
constexpr
    typename CSubsystemQueryMinimumMnemonic<M, topsubsystem, N, subsystem>::type
        CSubsystemQueryMinimumMnemonic<M, topsubsystem, N,
                                       subsystem>::QueryMinimumMnemonic;

template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
struct CSubsystemQueryDefaultMnemonic {
  using type =
      const_string<M + N - 1 + CMnemonics::COLON.length() +
                   CMnemonics::QUERY.length() + CMnemonics::SPACE.length() +
                   CMnemonics::DEFault.length()>;
  static constexpr type QueryDefaultMnemonic{
      topsubsystem + CMnemonics::COLON + subsystem + CMnemonics::QUERY +
      CMnemonics::SPACE + CMnemonics::DEFault};
};
template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
constexpr
    typename CSubsystemQueryDefaultMnemonic<M, topsubsystem, N, subsystem>::type
        CSubsystemQueryDefaultMnemonic<M, topsubsystem, N,
                                       subsystem>::QueryDefaultMnemonic;

template <std::size_t M, const const_string<M> &topsubsystem, std::size_t N,
          const const_string<N> &subsystem>
struct CNumberedSubsystemMnemonic {
  std::string operator()(const int idx) {
    return MakeMnemonicNumberedString(topsubsystem, idx, subsystem);
  };
};

///////////////////////////////>>>>>>>>>>
template <typename T>
struct CTopSubsystemMnemonicString {
  CTopSubsystemMnemonicString(std::string &topsubsystem)
      : topsubsystem{topsubsystem} {}
  std::string Mnemonic() { return topsubsystem; }
  std::string command() { return topsubsystem + CMnemonics::COLON.to_string(); }
  std::string query() { return topsubsystem + CMnemonics::QUERY.to_string(); }
  T operator[](int idx) { return T{topsubsystem + std::to_string(idx)}; }

 private:
  std::string topsubsystem;
};

template <typename T>
struct CSubsystemMnemonicString {
  CSubsystemMnemonicString(std::string &topsubsystem, std::string &subsystem)
      : topsubsystem{topsubsystem}, subsystem{subsystem} {}
  std::string Mnemonic() { return topsubsystem + subsystem; }
  std::string command() {
    return topsubsystem + subsystem + CMnemonics::COLON.to_string();
  }
  std::string query() {
    return topsubsystem + subsystem + CMnemonics::QUERY.to_string();
  }
  T operator[](int idx) {
    return T{topsubsystem, subsystem + std::to_string(idx)};
  }

 private:
  std::string topsubsystem;
  std::string subsystem;
};
/////////////<<<<<<<<<<<<<<<<<<<
}  // namespace scpi::mnemonics

#define CREATE_SUBSYSTEM_MNEMONIC(NAME, MNEMONIC)               \
  template <std::size_t N, const const_string<N> &topsubsystem> \
  struct C##NAME##SubsystemMnemonics                            \
      : public CSubsystemMnemonic<N, topsubsystem, sizeof(MNEMONIC), MNEMONIC>

#define ADD_SUBSYSTEM_COMMAND_MNEMONIC(MNEMONIC) \
 public                                          \
  CSubsystemCommandMnemonic<N, topsubsystem, sizeof(MNEMONIC), MNEMONIC>

#define ADD_SUBSYSTEM_QUERY_MNEMONIC(MNEMONIC) \
 public                                        \
  CSubsystemQueryMnemonic<N, topsubsystem, sizeof(MNEMONIC), MNEMONIC>

#define ADD_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(MNEMONIC) \
 public                                                \
  CSubsystemQueryMaximumMnemonic<N, topsubsystem, sizeof(MNEMONIC), MNEMONIC>

#define ADD_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(MNEMONIC) \
 public                                                \
  CSubsystemQueryMinimumMnemonic<N, topsubsystem, sizeof(MNEMONIC), MNEMONIC>

#define ADD_SUBSYSTEM_QUERY_DEFAULT_MNEMONIC(MNEMONIC) \
 public                                                \
  CSubsystemQueryDefaultMnemonic<N, topsubsystem, sizeof(MNEMONIC), MNEMONIC>

#define ADD_SUBSYSTEM_MNEMONIC(NAME, MNEMONIC)           \
  static C##NAME##SubsystemMnemonics<                    \
      sizeof(C##MNEMONIC##SubsystemMnemonics::Mnemonic), \
      C##MNEMONIC##SubsystemMnemonics::Mnemonic>         \
      NAME

#define CREATE_TOP_SUBSYSTEM_MNEMONIC(NAME, MNEMONIC) \
  struct C##NAME##SubsystemMnemonics                  \
      : public CTopSubsystemMnemonic<sizeof(MNEMONIC), MNEMONIC>

#define ADD_TOP_SUBSYSTEM_COMMAND_MNEMONIC(MNEMONIC) \
 public                                              \
  CTopSubsystemCommandMnemonic<sizeof(MNEMONIC), MNEMONIC>

#define ADD_TOP_SUBSYSTEM_QUERY_MNEMONIC(MNEMONIC) \
 public                                            \
  CTopSubsystemQueryMnemonic<sizeof(MNEMONIC), MNEMONIC>

#define ADD_TOP_SUBSYSTEM_QUERY_MAXIMUM_MNEMONIC(MNEMONIC) \
 public                                                    \
  CTopSubsystemQueryMaximumMnemonic<sizeof(MNEMONIC), MNEMONIC>

#define ADD_TOP_SUBSYSTEM_QUERY_MINIMUM_MNEMONIC(MNEMONIC) \
 public                                                    \
  CTopSubsystemQueryMinimumMnemonic<sizeof(MNEMONIC), MNEMONIC>

#define ADD_TOP_SUBSYSTEM_QUERY_DEFAULT_MNEMONIC(MNEMONIC) \
 public                                                    \
  CTopSubsystemQueryDefaultMnemonic<sizeof(MNEMONIC), MNEMONIC>

#define ADD_TOP_SUBSYSTEM_MNEMONIC(NAME, MNEMONIC)       \
  static C##NAME##SubsystemMnemonics<                    \
      sizeof(C##MNEMONIC##SubsystemMnemonics::Mnemonic), \
      C##MNEMONIC##SubsystemMnemonics::Mnemonic>         \
      NAME

#define SUBSYSTEM_MNEMONIC_TYPE(NAME) C##NAME##SubsystemMnemonics
