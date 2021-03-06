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

#include "scpi_base.h"

namespace scpi {
enum class QUEStionableStatus : unsigned int {
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

class STATusSubsystem {
 public:
  STATusSubsystem(const scpi_base &);

  template <typename register_type>
  void GetOPERationStatusEnable(register_type &,
                                const channel_type &channel = {}) const;
  template <typename register_type>
  void SetOPERationStatusEnable(const register_type &,
                                const channel_type &channel = {}) const;
  template <typename register_type>
  void GetOPERationStatusRegister(register_type &,
                                  const channel_type &channel = {}) const;
  template <typename register_type>
  void GetOPERationStatusEvent(register_type &,
                               const channel_type &channel = {}) const;
  //! \todo добавить PTR
  //! \todo добавить NTR

  template <typename register_type>
  void GetQUEStionableStatusEnable(register_type &,
                                   const channel_type &channel = {}) const;
  template <typename register_type>
  void SetQUEStionableStatusEnable(const register_type &,
                                   const channel_type &channel = {}) const;
  template <typename register_type>
  void GetQUEStionableStatusRegister(register_type &,
                                     const channel_type &channel = {}) const;
  template <typename register_type>
  void GetQUEStionableStatusEvent(register_type &,
                                  const channel_type &channel = {}) const;
  //! \todo добавить PTR
  //! \todo добавить NTR

  template <typename register_type>
  void GetQUEStionableStatusEnable(const QUEStionableStatus &, register_type &,
                                   const channel_type &channel = {}) const;
  template <typename register_type>
  void SetQUEStionableStatusEnable(const QUEStionableStatus &,
                                   const register_type &,
                                   const channel_type &channel = {}) const;
  template <typename register_type>
  void GetQUEStionableStatusRegister(const QUEStionableStatus &,
                                     register_type &,
                                     const channel_type &channel = {}) const;
  template <typename register_type>
  void GetQUEStionableStatusEvent(const QUEStionableStatus &, register_type &,
                                  const channel_type &channel = {}) const;

  STATusSubsystem() = delete;
  STATusSubsystem(const STATusSubsystem &) = delete;
  STATusSubsystem &operator=(const STATusSubsystem &) = delete;

 private:
  const scpi_base &_scpi;
};
}  // namespace scpi

#include "scpi_status_subsystem.hpp"
