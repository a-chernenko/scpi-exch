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

#ifndef REGISTER_TYPE_HPP
#define REGISTER_TYPE_HPP

namespace RegisterType {
namespace Detail {
template <typename RegisterType, typename BitMask, typename BitsType>
std::istream &operator>>(
    std::istream &lhs,
    RegisterTypeAbstract<RegisterType, BitMask, BitsType> &rhs) {
  RegisterType reg;
  lhs >> reg;
  rhs.SetRegister(reg);
  return lhs;
}

template <typename RegisterType, typename BitMask, typename BitsType>
std::ostream &operator<<(
    std::ostream &lhs,
    RegisterTypeAbstract<RegisterType, BitMask, BitsType> rhs) {
  RegisterType reg = rhs.GetRegister();
  lhs << reg;
  return lhs;
}

template <typename RegisterType, typename BitMask, typename BitsType>
RegisterTypeAbstract<RegisterType, BitMask, BitsType>::RegisterTypeAbstract(
    const RegisterType &val)
    : Data{val} {}

template <typename RegisterType, typename BitMask, typename BitsType>
RegisterTypeAbstract<RegisterType, BitMask, BitsType>::RegisterTypeAbstract(
    const std::string &val)
    : Data{static_cast<RegisterType>(std::stoi(val))} {}

template <typename RegisterType, typename BitMask, typename BitsType>
void RegisterTypeAbstract<RegisterType, BitMask, BitsType>::SetRegister(
    const RegisterType &val) {
  Data.Register = (val & static_cast<RegisterType>(BitMask::AllBits));
}

template <typename RegisterType, typename BitMask, typename BitsType>
RegisterType
RegisterTypeAbstract<RegisterType, BitMask, BitsType>::GetRegister() const {
  return Data.Register;
}

template <typename RegisterType, typename BitMask, typename BitsType>
std::string RegisterTypeAbstract<RegisterType, BitMask, BitsType>::to_string()
    const {
  return std::to_string(Data.Register);
}

template <typename RegisterType, typename BitMask, typename BitsType>
RegisterTypeAbstract<RegisterType, BitMask, BitsType>::DataType::DataType()
    : Register{} {}

template <typename RegisterType, typename BitMask, typename BitsType>
RegisterTypeAbstract<RegisterType, BitMask, BitsType>::DataType::DataType(
    const RegisterType &val)
    : Register{static_cast<RegisterType>(
          val & static_cast<RegisterType>(BitMask::AllBits))} {}

template <typename RegisterType, typename BitMask, typename BitsType>
void RegisterTypeAbstract<RegisterType, BitMask,
                          BitsType>::DataType::SetAllBits() {
  Register = static_cast<RegisterType>(BitMask::AllBits);
}

template <typename RegisterType, typename BitMask, typename BitsType>
void RegisterTypeAbstract<RegisterType, BitMask,
                          BitsType>::DataType::ClearAllBits() {
  Register = 0;
}
}  // namespace Detail
}  // namespace RegisterType

#endif  // REGISTER_TYPE_HPP
