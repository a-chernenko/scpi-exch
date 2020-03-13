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

#include <cstdint>
#include <sstream>
#include <string>
#include <type_traits>

namespace scpi {
using register_32bit_type = uint32_t;
using register_16bit_type = uint16_t;
using register_8bit_type = uint8_t;

namespace detail {
template <typename register_type, typename bit_mask, typename bits_type>
class register_abstract {
  union data_type;

 public:
  data_type data;
  register_abstract() = default;
  explicit register_abstract(const register_type&);
  explicit register_abstract(const std::string&);
  inline void set_register(const register_type&);
  inline register_type get_register() const;
  inline std::string to_string() const;

 private:
  union data_type {
   public:
    friend register_abstract;
    bits_type bits;
    data_type();
    explicit data_type(const register_type&);
    data_type& operator=(const data_type& val) {
      if (this == &val) return *this;
      _register = val._register;
      return *this;
    }
    inline void set_all_bits();
    inline void clear_all_bits();
    static_assert(std::is_same<register_type, register_8bit_type>::value ||
                      std::is_same<register_type, register_16bit_type>::value ||
                      std::is_same<register_type, register_32bit_type>::value,
                  "register_type is not equal register_8bit_type, "
                  "register_16bit_type or register_32bit_type!");
    static_assert(std::is_class<bits_type>::value, "wrong type of bits_type!");
    static_assert(std::is_enum<bit_mask>::value, "wrong type of bit_mask!");
    static_assert(sizeof(bits_type) == sizeof(register_type),
                  "bits_type is not equal register_type!");
    static_assert(std::is_same<typename std::underlying_type<bit_mask>::type,
                               register_type>::value,
                  "bit_mask is not underlying type of register_type!");

   private:
    register_type _register;
  };
};
}  // namespace detail

template <typename bit_mask, typename bits_type>
using register_8bit_abstract =
    detail::register_abstract<register_8bit_type, bit_mask, bits_type>;

template <typename bit_mask, typename bits_type>
using register_16bit_abstract =
    detail::register_abstract<register_16bit_type, bit_mask, bits_type>;

template <typename bit_mask, typename bits_type>
using register_32bit_abstract =
    detail::register_abstract<register_32bit_type, bit_mask, bits_type>;
}  // namespace scpi

#include "register_type.hpp"
