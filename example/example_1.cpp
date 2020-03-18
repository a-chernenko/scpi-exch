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

#include <iostream>
#include "scpi_api.h"

using namespace scpi;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) try {
  // >>> only for example >>>
  constexpr auto dot = make_const_string('.');
  constexpr auto ip_const_string =
      const_string_from_integer<signed, 192>::value + dot +
      const_string_from_integer<signed, 168>::value + dot +
      const_string_from_integer<signed, 0>::value + dot +
      const_string_from_integer<signed, 80>::value;
  constexpr auto parameter_name_const_string =
      MAKE_CONST_STRING_FROM_PARAMETER_NAME(ip_const_string);
  constexpr auto integer_const_string =
      MAKE_CONST_STRING_FROM_INTEGER(signed, -1234567890);
  constexpr auto scpi_const_string =
      MAKE_CONST_STRING_FROM_LITERAL_STRING("SCPI ");
  constexpr auto test_const_string =
      MAKE_CONST_STRING_FROM_LITERAL_STRING("TEST\n");
  constexpr auto scpi_test_const_string = scpi_const_string + test_const_string;
  std::cout << scpi_test_const_string.to_string();
  // <<< only for example <<<

  scpi_io scpi;
  scpi.ieee488_io.set_error_handler_enabled(true);
  try {
    scpi.open(ip_const_string.to_string());
  } catch (scpi::io_error &e) {
    std::cerr << e.what() << '\n';
    std::cerr << "can't open instrument\n";
  }
  if (scpi.is_opened()) {
    scpi.SYSTem.LOCK.lock();
    std::string idn{};
    scpi.ieee488_io.get_identification(idn);
    std::cout << idn << '\n';
    std::string test_info{};
    auto test_code = scpi.ieee488_io.self_test(test_info);
    std::cout << "test_code: " << test_code;
    if (!test_info.empty()) {
      std::cout << ", " << test_info << '\n';
    }
    std::cout << '\n';
    scpi.SYSTem.LOCK.release();
    scpi.close();
  }
  return 0;
} catch (...) {
  std::cerr << "\nunexpected exception\n";
  return 0;
}
