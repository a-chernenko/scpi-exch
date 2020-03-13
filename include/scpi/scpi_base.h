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

#if __cplusplus < 201703L
#error \
    "This file requires compiler and library support for the ISO C++ 2017 standard."
#endif

#include <memory>
#include <mutex>
#include <sstream>
#include <type_traits>
#include <vector>
#include "const_string.h"
#include "ieee488_io.h"
#include "scpi_channel_type.h"
#include "scpi_constants.h"
#include "scpi_units_type.h"

namespace scpi {
template <typename Base, typename... Args>
struct any_base_of;

template <typename Base, typename Arg, typename... Args>
struct any_base_of<Base, Arg, Args...> {
  static constexpr bool value =
      std::is_base_of<Base, Arg>::value || any_base_of<Base, Args...>::value;
};

template <typename Base, typename Derived>
struct any_base_of<Base, Derived> {
  static constexpr bool value = std::is_base_of<Base, Derived>::value;
};

template <typename Base, typename... Args>
struct all_base_of;

template <typename Base, typename Arg, typename... Args>
struct all_base_of<Base, Arg, Args...> {
  static constexpr bool value =
      std::is_base_of<Base, Arg>::value && all_base_of<Base, Args...>::value;
};

template <typename Base, typename Derived>
struct all_base_of<Base, Derived> {
  static constexpr bool value = std::is_base_of<Base, Derived>::value;
};

class SCPI_API scpi_base : public scpi::constants {
 public:
  scpi_base() = default;
  ~scpi_base() noexcept;
  inline void open(const std::string &, const unsigned short);
  inline bool is_opened() const noexcept;
  inline void close();
  template <size_t N, typename... ValueTypes>
  typename std::enable_if<
      !any_base_of<units_type_base, ValueTypes...>::value &&
      !any_base_of<channel_type, ValueTypes...>::value>::type
  command(const const_string<N> &, const ValueTypes &...) const;
  template <typename... ValueTypes>
  typename std::enable_if<
      !any_base_of<units_type_base, ValueTypes...>::value &&
      !any_base_of<channel_type, ValueTypes...>::value>::type
  command(const std::string &, const ValueTypes &...) const;
  template <size_t N, typename... ValueTypes>
  void command(const const_string<N> &, const channel_type &,
               const ValueTypes &...) const;
  template <typename... ValueTypes>
  void command(const std::string &, const channel_type &,
               const ValueTypes &...) const;
  template <size_t N, typename ValueType>
  void command(const const_string<N> &, const units_type_base &,
               const ValueType &) const;
  template <typename ValueType>
  void command(const std::string &, const units_type_base &,
               const ValueType &) const;
  template <size_t N>
  void command(const const_string<N> &, const units_type_base &) const;
  void command(const std::string &, const units_type_base &) const;
  template <size_t N>
  void command(const const_string<N> &) const;
  void command(const std::string &) const;
  template <size_t N, typename... ValueTypes>
  typename std::enable_if<
      !any_base_of<channel_type, ValueTypes...>::value>::type
  query(const const_string<N> &, ValueTypes &...) const;
  template <typename... ValueTypes>
  typename std::enable_if<
      !any_base_of<channel_type, ValueTypes...>::value>::type
  query(const std::string &, ValueTypes &...) const;
  template <size_t N, typename... ValueTypes>
  void query(const const_string<N> &, const channel_type &,
             ValueTypes &...) const;
  template <typename... ValueTypes>
  void query(const std::string &, const channel_type &, ValueTypes &...) const;
  template <size_t N>
  void query(const const_string<N> &, std::string &) const;
  void query(const std::string &, std::string &) const;
  static void split_separated_string(const std::string &, const std::string &,
                                     std::vector<std::string> &);
  static void remove_quotes(std::string &);
  static void remove_space(std::string &);
  void set_query_timeout(const unsigned int) noexcept;
  void set_query_timeout() noexcept;
  unsigned int get_query_timeout() const noexcept;

 protected:
  scpi::io io;

 public:
  scpi::ieee488_io ieee488_io{io};

  scpi_base(const scpi_base &) = delete;
  scpi_base &operator=(const scpi_base &) = delete;

 private:
  static std::mutex _mutex;
  unsigned int _query_timeout_ms{query_timeout_ms};
  static void remove_char(std::string &, const char);
  static void add_channel(std::string &, const channel_type &);
  void make_separated_string(std::stringstream &, const char) const {};
  template <typename Arg, typename... Args>
  void make_separated_string(std::stringstream &, const char, const Arg &,
                             const Args &...) const;
  void parse_separated_string(std::stringstream &) const {};
  template <typename Arg, typename... Args>
  void parse_separated_string(std::stringstream &ss, Arg &, Args &...) const;
  template <size_t N, typename... ValueTypes>
  void command_base(const const_string<N> &, const ValueTypes &...) const;
  template <typename... ValueTypes>
  void command_base(const std::string &, const ValueTypes &...) const;
  template <size_t N, typename... ValueTypes>
  void query_base(const const_string<N> &, ValueTypes &...) const;
  template <typename... ValueTypes>
  void query_base(const std::string &, ValueTypes &...) const;
};
}  // namespace scpi

#include "scpi_base.hpp"
