#include "../config.h"

class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        std::deque<std::string> frame;

        for (int i = 0; i < (int) path.length(); ++i) {
            if (path[i] == '/') {
                int end = i + 1;
                while (end < (int) path.length() && path[end] != '/') {
                    ++end;
                }

                std::string sub_path = path.substr(i, end - i);
                switch(sub_path.length()) {
                    case 0:
                    case 1:
                        {
                            break;
                        }
                    case 2:
                        {
                            if (sub_path.back() != '.') {
                                frame.push_back(sub_path);
                            }
                            break;
                        }
                    case 3:
                        {
                            if (sub_path.back() != '.') {
                                frame.push_back(sub_path);
                            } else if (!frame.empty()) {
                                frame.pop_back();
                            }
                            break;
                        }
                    default:
                        {
                            frame.push_back(sub_path);
                            break;
                        }
                }
            }
        }

        std::string result;

        for (auto &it : frame) {
            result.append(it);
        }

        return result.length() ? result : "/";
    }
};

