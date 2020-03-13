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

namespace scpi {
namespace detail {
template <typename register_type, typename bit_mask, typename bits_type>
std::istream &operator>>(
    std::istream &lhs,
    register_abstract<register_type, bit_mask, bits_type> &rhs) {
  register_type reg;
  lhs >> reg;
  rhs.set_register(reg);
  return lhs;
}

template <typename register_type, typename bit_mask, typename bits_type>
std::ostream &operator<<(
    std::ostream &lhs,
    register_abstract<register_type, bit_mask, bits_type> rhs) {
  register_type reg = rhs.get_register();
  lhs << reg;
  return lhs;
}

template <typename register_type, typename bit_mask, typename bits_type>
register_abstract<register_type, bit_mask, bits_type>::register_abstract(
    const register_type &val)
    : data{val} {}

template <typename register_type, typename bit_mask, typename bits_type>
register_abstract<register_type, bit_mask, bits_type>::register_abstract(
    const std::string &val)
    : data{static_cast<register_type>(std::stoi(val))} {}

template <typename register_type, typename bit_mask, typename bits_type>
void register_abstract<register_type, bit_mask, bits_type>::set_register(
    const register_type &val) {
  data._register = (val & static_cast<register_type>(bit_mask::all_bits));
}

template <typename register_type, typename bit_mask, typename bits_type>
register_type
register_abstract<register_type, bit_mask, bits_type>::get_register() const {
  return data._register;
}

template <typename register_type, typename bit_mask, typename bits_type>
std::string register_abstract<register_type, bit_mask, bits_type>::to_string()
    const {
  return std::to_string(data._register);
}

template <typename register_type, typename bit_mask, typename bits_type>
register_abstract<register_type, bit_mask, bits_type>::data_type::data_type()
    : _register{} {}

template <typename register_type, typename bit_mask, typename bits_type>
register_abstract<register_type, bit_mask, bits_type>::data_type::data_type(
    const register_type &val)
    : _register{static_cast<register_type>(
          val & static_cast<register_type>(bit_mask::all_bits))} {}

template <typename register_type, typename bit_mask, typename bits_type>
void register_abstract<register_type, bit_mask,
                       bits_type>::data_type::set_all_bits() {
  _register = static_cast<register_type>(bit_mask::all_bits);
}

template <typename register_type, typename bit_mask, typename bits_type>
void register_abstract<register_type, bit_mask,
                       bits_type>::data_type::clear_all_bits() {
  _register = 0;
}
}  // namespace detail
}  // namespace scpi
