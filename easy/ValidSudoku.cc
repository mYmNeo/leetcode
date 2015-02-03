#include "config.h"

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char> > &board)
    {
        int digit[256];

        for (int i = 0; i < 9; i++) {
            std::memset(digit, 0x00, sizeof(int) * 256);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    digit[(int) board[i][j]]++;
                    if (digit[(int) board[i][j]] > 1) {
                        return false;
                    }
                }
            }
        }

        for (int j = 0; j < 9; j++) {
            std::memset(digit, 0x00, sizeof(int) * 256);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    digit[(int) board[i][j]]++;
                    if (digit[(int) board[i][j]] > 1) {
                        return false;
                    }
                }
            }
        }

        int loop = 0;
        while (loop < 3) {
            for (int k = 0; k < 3; k++) {
                std::memset(digit, 0x00, sizeof(int) * 256);
                for (int i = loop * 3; i < (loop + 1) * 3; i++) {
                    for (int j = k * 3 ; j < (k + 1) * 3; j++) {
                        if (board[i][j] == '.') {
                            continue;
                        } else {
                            digit[(int) board[i][j]]++;
                            if (digit[(int) board[i][j]] > 1) {
                                return false;
                            }
                        }
                    }
                }
            }
            loop++;
        }

        return true;
    }
};

