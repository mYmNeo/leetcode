#include "../config.h"

class Solution
{
public:
    std::vector<std::vector<std::string> > solveNQueens(int n)
    {
        ret.clear();
        if (n == 0) {
            return ret;
        }

        std::vector<std::string> res(n, std::string(n, '.'));

        for (int j = 0; j < n; ++j) {
            if (res[0][j] == '.' && check_valid(res, 0, j, n)) {
                res[0][j] = 'Q';
                place_a_queen(res, n, 1);
                res[0][j] = '.';
            }
        }
        
        return ret;
    }
private:
    void place_a_queen(std::vector<std::string> &chess, const int &n, const int put)
    {
        if (put == n) {
            ret.push_back(chess);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (chess[put][j] == '.' && check_valid(chess, put, j, n)) {
                chess[put][j] = 'Q';
                place_a_queen(chess, n, put + 1);
                chess[put][j] = '.';
            }
        }
    }

    bool check_valid(std::vector<std::string> &chess, const int &row, const int &col, const int &n)
    {
        for (int i = 0; i < n; ++i) {
            if (chess[i][col] == 'Q') {
                return false;
            }
        }

        for (int j = 0; j < n; ++j) {
            if (chess[row][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i < n && j < n; ++i, ++j) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
private:
    std::vector<std::vector<std::string> > ret;
};

