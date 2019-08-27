#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> ret;
    while (i < (int)nums1.size() && j < (int)nums2.size()) {
      if (nums1[i] == nums2[j]) {
        ret.push_back(nums1[i]);
        ++i;
        ++j;
        continue;
      }

      if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        ++j;
      }
    }
    return ret;
  }
};