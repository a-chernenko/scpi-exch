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

namespace detail {
namespace {
template <std::size_t...>
struct index_seq {};
template <std::size_t N, std::size_t... S>
struct gen_index_seq : gen_index_seq<N - 1, N - 1, S...> {};
template <std::size_t... S>
struct gen_index_seq<0, S...> {
  using type = index_seq<S...>;
};
}  // namespace
}  // namespace detail

template <std::size_t N, std::size_t... NIds, std::size_t M,
          std::size_t... MIds>
constexpr const_string<N + M - 1> concat_char_arrays_impl(
    const std::array<char, N>& lhs, detail::index_seq<NIds...>,
    const std::array<char, M>& rhs, detail::index_seq<MIds...>) {
  return const_string<N + M - 1>{
      std::array<char, N + M - 1>{{lhs[NIds]..., rhs[MIds]..., '\0'}}};
};

template <std::size_t N, std::size_t M>
constexpr const_string<N + M - 1> operator+(const const_string<N>& lhs,
                                            const const_string<M>& rhs) {
  using lind = typename ::detail::gen_index_seq<N - 1>::type;
  using rind = typename ::detail::gen_index_seq<M - 1>::type;
  return concat_char_arrays_impl(lhs.data, lind(), rhs.data, rind());
};
