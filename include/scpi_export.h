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

#ifndef SCPI_EXPORT_H
#define SCPI_EXPORT_H

#if defined(_WIN32) || defined(_WIN64)
#define SCPI_API __declspec(dllexport)
#elif defined(linux)
#define SCPI_API __attribute__((visibility("default")))
#endif
#ifndef SCPI_API
#define SCPI_API
#endif

#endif  // SCPI_EXPORT_H
