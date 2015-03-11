#include "../config.h"

class Solution
{
public:
    std::string fractionToDecimal(int numberator, int denominator)
    {
        if (numberator == 0) {
            return "0";
        }

        std::string result;
        int64_t num = numberator, deno = denominator;
        bool flag = false;

        if (num < 0) {
            if (deno > 0) {
                flag = true;
            }
        } else {
            if (deno < 0) {
                flag = true;
            }
        }

        num = num > 0 ? num : -num;
        deno = deno > 0 ? deno : -deno;

        if (num > deno) {
            result.append(std::to_string(num / deno));
            num = num % deno;
        }

        if (result.empty()) {
            result.push_back('0');
        }

        if (num == 0) {
            return flag ? ("-" + result) : result;
        }

        result.push_back('.');

        std::unordered_map<int64_t, int64_t> repeat;
        while (num) {
            if (repeat.find(num) == repeat.end()) {
                repeat[num] = result.size();
                num *= 10;
                result.push_back('0' + num / deno);
                num = num % deno;
            } else {
                int64_t cut = repeat[num];
                result = result.substr(0, cut) + "(" + result.substr(cut) + ")";
                num = 0;
            }
        }

        return flag ? ("-" + result) : result;
    }
};

