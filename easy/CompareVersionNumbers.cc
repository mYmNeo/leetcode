#include "config.h"

class Solution
{
public:
    int compareVersion(std::string version1, std::string version2)
    {
        std::string::size_type pos1 = 0, pos2 = 0;
        std::string::size_type end1, end2;
        int v1 = 0, v2 = 0;
        int ret = 0;

        while (1) {
            if (pos1 == version1.length() && pos2 == version2.length()) {
                break;
            }

            v1 = 0;
            v2 = 0;

            if (pos1 < version1.length()) {
                end1 = version1.find_first_of('.', pos1);
                if (end1 == std::string::npos) {
                    v1 = std::atoi(version1.substr(pos1).c_str());
                    pos1 = version1.length();
                } else {
                    v1 = std::atoi(version1.substr(pos1, end1 - pos1).c_str());
                    pos1 = end1 + 1;
                }
            }

            if (pos2 < version2.length()) {
                end2 = version2.find_first_of('.', pos2);
                if (end2 == std::string::npos) {
                    v2 = std::atoi(version2.substr(pos2).c_str());
                    pos2 = version2.length();
                } else {
                    v2 = std::atoi(version2.substr(pos2, end2 - pos2).c_str());
                    pos2 = end2 + 1;
                }
            }


            if (v1 == v2) {
                ret = 0;
                continue;
            }

            if (v1 > v2) {
                return 1;
            }

            return -1;
        }

        return ret;
    }
};

