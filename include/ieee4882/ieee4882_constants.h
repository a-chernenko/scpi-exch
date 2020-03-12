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

#ifndef IEEE4882_CONSTANTS_H
#define IEEE4882_CONSTANTS_H

namespace Ieee4882 {
struct CIeee4882Constants {
 protected:
  static const unsigned int QueryTimeoutDefault_ms{10 * 1000};
  static const unsigned int SelfTestTimeout_ms{5 * 60 * 1000};
  CIeee4882Constants() = default;
};
}  // namespace Ieee4882

#endif  // IEEE4882_CONSTANTS_H
