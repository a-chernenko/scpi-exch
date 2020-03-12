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

#ifndef SCPI_STATUS_SUBSYSTEM_H
#define SCPI_STATUS_SUBSYSTEM_H

#include "scpi_base.h"

namespace Scpi {
enum class QUEStionableStatusType : unsigned int {
  VOLTage,
  CURRent,
  TIME,
  POWer,
  TEMPerature,
  FREQuency,
  PHASe,
  MODulation,
  CALibration,
  INTegrity
};

class CSTATusSubsystem {
 public:
  CSTATusSubsystem(const CScpiBase &);

  template <typename RegisterType>
  void GetOPERationStatusEnable(RegisterType &,
                                const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void SetOPERationStatusEnable(const RegisterType &,
                                const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void GetOPERationStatusRegister(RegisterType &,
                                  const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void GetOPERationStatusEvent(RegisterType &,
                               const ChannelType &channel = {}) const;
  //! \todo добавить PTR
  //! \todo добавить NTR

  template <typename RegisterType>
  void GetQUEStionableStatusEnable(RegisterType &,
                                   const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void SetQUEStionableStatusEnable(const RegisterType &,
                                   const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void GetQUEStionableStatusRegister(RegisterType &,
                                     const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void GetQUEStionableStatusEvent(RegisterType &,
                                  const ChannelType &channel = {}) const;
  //! \todo добавить PTR
  //! \todo добавить NTR

  template <typename RegisterType>
  void GetQUEStionableStatusEnable(const QUEStionableStatusType &,
                                   RegisterType &,
                                   const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void SetQUEStionableStatusEnable(const QUEStionableStatusType &,
                                   const RegisterType &,
                                   const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void GetQUEStionableStatusRegister(const QUEStionableStatusType &,
                                     RegisterType &,
                                     const ChannelType &channel = {}) const;
  template <typename RegisterType>
  void GetQUEStionableStatusEvent(const QUEStionableStatusType &,
                                  RegisterType &,
                                  const ChannelType &channel = {}) const;

  CSTATusSubsystem() = delete;
  CSTATusSubsystem(const CSTATusSubsystem &) = delete;
  CSTATusSubsystem &operator=(const CSTATusSubsystem &) = delete;

 private:
  const CScpiBase &m_Scpi;
};
}  // namespace Scpi

#include "scpi_status_subsystem.hpp"

#endif  // SCPI_STATUS_SUBSYSTEM_H
