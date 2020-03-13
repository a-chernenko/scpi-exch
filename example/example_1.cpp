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
  scpi_io scpi;
  scpi.ieee488_io.set_error_handler_enabled(true);
  try {
    scpi.open("192.168.0.104");
  } catch (scpi::io_error &e) {
    std::cerr << "\ncan't open instrument\n";
  }
  if (scpi.is_opened()) {
    scpi.SYSTem.LOCK.Lock();
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
    scpi.SYSTem.LOCK.Release();
    scpi.close();
  }
  return 0;
} catch (...) {
  std::cerr << "\nunexpected exception\n";
  return 0;
}
