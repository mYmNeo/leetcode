#include "../config.h"

class Codec {
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string code;
    for (auto s : strs) {
      code.append(::to_string(s.length()));
      code.append("@");
      code.append(s);
    }
    return code;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> data;
    for (int i = 0; i < (int)s.length();) {
      auto pos = s.find_first_of('@', i);
      if (pos != string::npos) {
        auto len = ::atoi(s.substr(i, pos - i).c_str());
        data.push_back(s.substr(pos + 1, len));
        i = pos + len;
      }
      ++i;
    }
    return data;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));