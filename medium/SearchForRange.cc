#include "../config.h"

class Solution {
public:
  std::vector<int> searchRange(int A[], int n, int target) {
    std::vector<int> ret;

    ret.push_back(lower_bound(A, 0, n - 1, target));
    ret.push_back(upper_bound(A, 0, n - 1, target));

    if (ret[0] == -1 || ret[1] == -1) {
      std::fill(ret.begin(), ret.end(), -1);
    }

    return ret;
  }

private:
  int lower_bound(int A[], int start, int end, int target) {
    while (start < end) {
      int mid = (start + end) >> 1;

      if (A[mid] < target) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return A[start] == target ? start : -1;
  }

  int upper_bound(int A[], int start, int end, int target) {
    while (start < end) {
      int mid = (start + end) >> 1;

      if (A[mid] > target) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    if (A[start] == target) {
      return start;
    } else if (A[start] > target) {
      return start - 1;
    }
    return -1;
  }
};
