#include "../config.h"

class Solution
{
public:
    bool isNumber(std::string s)
    {
        int i = 0;

        /** trim left blank */
        while (i < (int) s.length() && s[i] == ' ') {
            ++i;
        }

        s = s.substr(i);

        if (s.length() == 0) {
            return false;
        }

        i = s.length() - 1;
        while (s[i] == ' ') {
            --i;
        }

        s = s.substr(0, i + 1);

        i = 0;
        /** sign match */
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }

        int round = 0, decimal = 0, notation = 0;
        /** collect digit as many as possible */
        while (i < (int) s.length() && ::isdigit(s[i])) {
            ++round;
            ++i;
        }

        /** full digit */
        if (i == (int) s.length() && round > 0) {
            return true;
        }

        if (s[i] == '.') {
            ++i;

            decimal = 0;
            /** collect digit as many as possible */
            while (i < (int) s.length() && ::isdigit(s[i])) {
                ++decimal;
                ++i;
            }

            /** a decimal */
            if (i == (int) s.length() && (round || decimal)) {
                return true;
            }

            if ((s[i] == 'e' || s[i] == 'E') && (round || decimal)) {
                ++i;
                /** sign match */
                if (s[i] == '+' || s[i] == '-') {
                    ++i;
                }

                notation = 0;
                /** collect digit as many as possible */
                while (i < (int) s.length() && ::isdigit(s[i])) {
                    ++notation;
                    ++i;
                }
                
                /** scientific notation */
                if (i == (int) s.length() && notation > 0) {
                    return true;
                }
            }
        } else if ((s[i] == 'e' || s[i] == 'E') && round > 0) {
            ++i;
            /** sign match */
            if (s[i] == '+' || s[i] == '-') {
                ++i;
            }

            notation = 0;
            /** collect digit as many as possible */
            while (i < (int) s.length() && ::isdigit(s[i])) {
                ++notation;
                ++i;
            }
            
            /** scientific notation */
            if (i == (int) s.length() && notation > 0) {
                return true;
            }
        }

        return false;
    }
};

