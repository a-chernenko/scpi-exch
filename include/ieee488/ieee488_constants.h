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
namespace ieee488 {
struct constants {
 protected:
  static const unsigned int query_timeout_ms{10 * 1000};
  static const unsigned int self_test_timeout_ms{5 * 60 * 1000};
  constants() = default;
};
}  // namespace ieee488
}  // namespace scpi
