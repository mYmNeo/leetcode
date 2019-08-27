#include "../config.h"

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    if (board.size() == 0 || word.length() == 0) {
      return false;
    }

    std::vector<std::vector<bool>> visit(
        board.size(), std::vector<bool>(board.front().size(), false));
    bool ret = false;
    for (int i = 0; i < (int)board.size(); ++i) {
      for (int j = 0; j < (int)board.front().size(); ++j) {
        if (!visit[i][j] && board[i][j] == word.front()) {
          visit[i][j] = true;
          ret = exist_helper(board, word, visit, i, j, 1);
          if (ret) {
            return true;
          }
          visit[i][j] = false;
        }
      }
    }

    return false;
  }

private:
  bool exist_helper(std::vector<std::vector<char>> &board, std::string &word,
                    std::vector<std::vector<bool>> &visit, int x, int y,
                    int pos) {
    if (pos == (int)word.length()) {
      return true;
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    bool ret = false;
    for (int i = 0; i < 4; ++i) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];

      if (new_x >= 0 && new_x < (int)board.size() && new_y >= 0 &&
          new_y < (int)board.front().size() && !visit[new_x][new_y]) {
        if (board[new_x][new_y] == word[pos]) {
          visit[new_x][new_y] = true;
          ret = exist_helper(board, word, visit, new_x, new_y, pos + 1);
          if (ret) {
            return true;
          }
          visit[new_x][new_y] = false;
        }
      }
    }

    return false;
  }
};
