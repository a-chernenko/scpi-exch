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

#ifndef REGISTER_TYPE_H
#define REGISTER_TYPE_H

#include <cstdint>
#include <sstream>
#include <string>
#include <type_traits>


namespace RegisterType {
using Register32BitType = uint32_t;
using Register16BitType = uint16_t;
using Register8BitType = uint8_t;

namespace Detail {
template <typename RegisterType, typename BitMask, typename BitsType>
class RegisterTypeAbstract {
  union DataType;

 public:
  DataType Data;
  RegisterTypeAbstract() = default;
  explicit RegisterTypeAbstract(const RegisterType&);
  explicit RegisterTypeAbstract(const std::string&);
  inline void SetRegister(const RegisterType&);
  inline RegisterType GetRegister() const;
  inline std::string to_string() const;

 private:
  union DataType {
   public:
    friend RegisterTypeAbstract;
    BitsType Bits;
    DataType();
    explicit DataType(const RegisterType&);
    DataType& operator=(const DataType& val) {
      if (this == &val) return *this;
      Register = val.Register;
      return *this;
    }
    inline void SetAllBits();
    inline void ClearAllBits();
    static_assert(std::is_same<RegisterType, Register8BitType>::value ||
                      std::is_same<RegisterType, Register16BitType>::value ||
                      std::is_same<RegisterType, Register32BitType>::value,
                  "RegisterType is not equal Register8BitType, "
                  "Register16BitType or Register32BitType!");
    static_assert(std::is_class<BitsType>::value, "Wrong type of BitsType!");
    static_assert(std::is_enum<BitMask>::value, "Wrong type of BitMask!");
    static_assert(sizeof(BitsType) == sizeof(RegisterType),
                  "BitsType is not equal RegisterType!");
    static_assert(std::is_same<typename std::underlying_type<BitMask>::type,
                               RegisterType>::value,
                  "BitMask is not underlying type of RegisterType!");

   private:
    RegisterType Register;
  };
};
}  // namespace Detail

template <typename BitMask, typename BitsType>
using Register8BitTypeAbstract =
    Detail::RegisterTypeAbstract<Register8BitType, BitMask, BitsType>;

template <typename BitMask, typename BitsType>
using Register16BitTypeAbstract =
    Detail::RegisterTypeAbstract<Register16BitType, BitMask, BitsType>;

template <typename BitMask, typename BitsType>
using Register32BitTypeAbstract =
    Detail::RegisterTypeAbstract<Register32BitType, BitMask, BitsType>;
}  // namespace RegisterType

#include "register_type.hpp"

#endif  // REGISTER_TYPE_H
