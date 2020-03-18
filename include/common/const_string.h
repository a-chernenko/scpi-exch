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

#include <array>
#include <iostream>
#include <string>

template <std::size_t N>
class const_string {
 public:
  using type = const_string<N>;
  std::array<char, N> data;
  constexpr const_string(const std::array<char, N> &arr) : data(arr) {}
  constexpr std::size_t length() const noexcept { return N - 1; }
  constexpr std::size_t size() const noexcept { return N; }
  constexpr char operator[](const std::size_t i) const {
    return ((i < N - 1) ? data[i] : '\0');
  }
  std::string to_string() const { return std::string{data.data()}; }
  friend std::ostream &operator<<(std::ostream &lhs, const const_string &rhs) {
    lhs << rhs.to_string();
    return lhs;
  }
  const_string() = delete;
};

namespace const_string_detail {
template <uint8_t... digits>
struct positive_to_chars {
  using type = std::array<char, sizeof...(digits) + 1>;
  static constexpr type value{{('0' + digits)..., '\0'}};
  positive_to_chars() = delete;
  positive_to_chars(const positive_to_chars &) = delete;
  positive_to_chars &operator=(const positive_to_chars &) = delete;
};

template <uint8_t... digits>
struct negative_to_chars {
  using type = std::array<char, sizeof...(digits) + 2>;
  static constexpr type value{{'-', ('0' + digits)..., '\0'}};
  negative_to_chars() = delete;
  negative_to_chars(const negative_to_chars &) = delete;
  negative_to_chars &operator=(const negative_to_chars &) = delete;
};

template <bool neg, uint8_t... digits>
struct to_chars : positive_to_chars<digits...> {};

template <uint8_t... digits>
struct to_chars<true, digits...> : negative_to_chars<digits...> {};

template <bool neg, uintmax_t val, uint8_t... digits>
struct integer_expands : integer_expands<neg, val / 10, val % 10, digits...> {};

template <bool neg, uint8_t... digits>
struct integer_expands<neg, 0, digits...> : to_chars<neg, digits...> {};

template <bool neg>
struct integer_expands<neg, 0> : to_chars<neg, 0> {};

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored \
    "-Wtype-limits"  // comparison of unsigned expression < 0 is always false
#endif
template <typename T>
constexpr bool is_negative(const T num) {
  return (num < 0);
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4146)  // unary minus operator applied to unsigned
                                 // type, result still unsigned
#endif
template <typename T>
constexpr uintmax_t cabs(const T num) {
  return (is_negative(num)) ? -num : num;
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif

template <typename Integer, Integer num>
struct const_string_from
    : integer_expands<is_negative(num), const_string_detail::cabs(num)> {};

template <intmax_t val, std::size_t digits = 0>
struct number_of_digits_impl {
  static constexpr const std::size_t &value{
      number_of_digits_impl<val / 10, digits + 1>::value};
};

template <std::size_t digits>
struct number_of_digits_impl<0, digits> {
  static constexpr std::size_t value{digits};
};
}  // namespace const_string_detail

template <intmax_t val>
struct number_of_digits : const_string_detail::number_of_digits_impl<val> {};

template <typename Integer, Integer num>
struct const_string_from_integer {
  using type = const_string<sizeof(
      typename const_string_detail::const_string_from<Integer, num>::type)>;
  static constexpr type value{const_string<sizeof(type)>{
      const_string_detail::const_string_from<Integer, num>::value}};
};

constexpr auto make_const_string(const char ch) {
  return const_string<2>{std::array<char, 2>{ch}};
}

#define MAKE_CONST_STRING_FROM_LITERAL_STRING(LITERAL_STRING)   \
  const_string<sizeof(LITERAL_STRING)> {                        \
    std::array<char, sizeof(LITERAL_STRING)> { LITERAL_STRING } \
  }

#define MAKE_CONST_STRING_FROM_PARAMETER_NAME(PARAMETER_NAME)     \
  const_string<sizeof(#PARAMETER_NAME)> {                         \
    std::array<char, sizeof(#PARAMETER_NAME)> { #PARAMETER_NAME } \
  }

#define MAKE_CONST_STRING_FROM_INTEGER(INTEGER_TYPE, INTEGER_VALUE)            \
  const_string<sizeof(                                                         \
      const_string<sizeof(typename const_string_detail::const_string_from<     \
                          INTEGER_TYPE, INTEGER_VALUE>::type)>)> {             \
    const_string_detail::const_string_from<INTEGER_TYPE, INTEGER_VALUE>::value \
  }

#include "const_string.hpp"
