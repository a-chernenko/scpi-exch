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

#include <algorithm>
#include "scpi.h"

using std::string;
using std::vector;
using namespace Scpi;
using namespace Hardware;
using namespace Ieee4882;

CScpiBase::~CScpiBase() noexcept {
  if (IsOpened()) try {
      Close();
    } catch (...) {
    }
}

void CScpiBase::SetQueryTimeout() noexcept {
  m_QueryTimeout_ms = QueryTimeoutDefault_ms;
}

void CScpiBase::SetQueryTimeout(const unsigned int timeout_ms) noexcept {
  m_QueryTimeout_ms = timeout_ms;
}

unsigned int CScpiBase::GetQueryTimeout() const noexcept {
  return m_QueryTimeout_ms;
}

void CScpiBase::SplitSeparatedString(const string &unsplitted,
                                     const string &separator,
                                     vector<string> &splitted) {
  string::size_type start{};
  string::size_type index = unsplitted.find(separator);
  while (index != string::npos) {
    splitted.push_back(unsplitted.substr(start, index));
    index += separator.length();
    start += index;
    index = unsplitted.substr(start).find(separator);
  };
  splitted.push_back(unsplitted.substr(start));
}

void CScpiBase::RemoveCharInString(std::string &str,
                                   const char char_to_remove) {
  auto begin = str.begin();
  auto end = str.end();
  auto isEqual = [=](const char ch) -> bool { return (ch == char_to_remove); };
  auto res = std::remove_if(begin, end, isEqual);
  str.resize(res - begin);
}

void CScpiBase::RemoveQuotesInString(string &str) {
  const char double_quote_char{'\"'};
  RemoveCharInString(str, double_quote_char);
}

void CScpiBase::RemoveSpaceInString(string &str) {
  const char space_char{' '};
  RemoveCharInString(str, space_char);
}

void CScpiBase::AddChannelToString(string &str, const ChannelType &channel) {
  str += " (@";
  str += channel.to_string();
  str += ")";
}

void CScpiBase::Command(const std::string &command) const {
  std::lock_guard<std::mutex> lock(m_Mutex);
  m_Hardware.WriteLine(command);
  m_Ieee4882.ErrorHandler();
}

void CScpiBase::Command(const std::string &command,
                        const UnitsTypeBase &unit) const {
  CommandBase(command, unit.to_string());
}

void CScpiBase::Query(const std::string &query, std::string &value) const {
  std::lock_guard<std::mutex> lock(m_Mutex);
  m_Hardware.WriteLine(query);
  bool readTimeout{};
  try {
    m_Hardware.ReadLine(value, QueryTimeoutDefault_ms);
  } catch (HardwareException::ReadTimeout &) {
    readTimeout = true;
  }
  m_Ieee4882.ErrorHandler();
  if (readTimeout) throw HardwareException::ReadTimeout();
}
