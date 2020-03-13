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

class SCPI_API scpi_base : public CScpiConstants {
 public:
  scpi_base() = default;
  ~scpi_base() noexcept;
  inline void open(const std::string &, const unsigned short);
  inline bool is_opened() const noexcept;
  inline void close();
  template <size_t N, typename... ValueTypes>
  typename std::enable_if<!any_base_of<UnitsTypeBase, ValueTypes...>::value &&
                          !any_base_of<ChannelType, ValueTypes...>::value>::type
  Command(const const_string<N> &, const ValueTypes &...) const;
  template <typename... ValueTypes>
  typename std::enable_if<!any_base_of<UnitsTypeBase, ValueTypes...>::value &&
                          !any_base_of<ChannelType, ValueTypes...>::value>::type
  Command(const std::string &, const ValueTypes &...) const;
  template <size_t N, typename... ValueTypes>
  void Command(const const_string<N> &, const ChannelType &,
               const ValueTypes &...) const;
  template <typename... ValueTypes>
  void Command(const std::string &, const ChannelType &,
               const ValueTypes &...) const;
  template <size_t N, typename ValueType>
  void Command(const const_string<N> &, const UnitsTypeBase &,
               const ValueType &) const;
  template <typename ValueType>
  void Command(const std::string &, const UnitsTypeBase &,
               const ValueType &) const;
  template <size_t N>
  void Command(const const_string<N> &, const UnitsTypeBase &) const;
  void Command(const std::string &, const UnitsTypeBase &) const;
  template <size_t N>
  void Command(const const_string<N> &) const;
  void Command(const std::string &) const;
  template <size_t N, typename... ValueTypes>
  typename std::enable_if<!any_base_of<ChannelType, ValueTypes...>::value>::type
  Query(const const_string<N> &, ValueTypes &...) const;
  template <typename... ValueTypes>
  typename std::enable_if<!any_base_of<ChannelType, ValueTypes...>::value>::type
  Query(const std::string &, ValueTypes &...) const;
  template <size_t N, typename... ValueTypes>
  void Query(const const_string<N> &, const ChannelType &,
             ValueTypes &...) const;
  template <typename... ValueTypes>
  void Query(const std::string &, const ChannelType &, ValueTypes &...) const;
  template <size_t N>
  void Query(const const_string<N> &, std::string &) const;
  void Query(const std::string &, std::string &) const;
  static void SplitSeparatedString(const std::string &, const std::string &,
                                   std::vector<std::string> &);
  static void RemoveQuotesInString(std::string &);
  static void RemoveSpaceInString(std::string &);
  void SetQueryTimeout(const unsigned int) noexcept;
  void SetQueryTimeout() noexcept;
  unsigned int GetQueryTimeout() const noexcept;

 protected:
  scpi::io io;

 public:
  scpi::ieee488_io ieee488_io{io};

  scpi_base(const scpi_base &) = delete;
  scpi_base &operator=(const scpi_base &) = delete;

 private:
  static std::mutex _mutex;
  unsigned int m_QueryTimeout_ms{query_timeout_ms};
  static void RemoveCharInString(std::string &, const char);
  static void AddChannelToString(std::string &, const ChannelType &);
  void MakeSeparatedString(std::stringstream &, const char) const {};
  template <typename Arg, typename... Args>
  void MakeSeparatedString(std::stringstream &, const char, const Arg &,
                           const Args &...) const;
  void ParseSeparatedString(std::stringstream &) const {};
  template <typename Arg, typename... Args>
  void ParseSeparatedString(std::stringstream &ss, Arg &, Args &...) const;
  template <size_t N, typename... ValueTypes>
  void CommandBase(const const_string<N> &, const ValueTypes &...) const;
  template <typename... ValueTypes>
  void CommandBase(const std::string &, const ValueTypes &...) const;
  template <size_t N, typename... ValueTypes>
  void QueryBase(const const_string<N> &, ValueTypes &...) const;
  template <typename... ValueTypes>
  void QueryBase(const std::string &, ValueTypes &...) const;
};
}  // namespace scpi

#include "scpi_base.hpp"
