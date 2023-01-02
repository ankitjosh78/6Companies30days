#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int n = (int)nums.size();
    int left = -1, right = n;
    int cur_min = nums[n - 1], cur_max = nums[0];
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] <= cur_min) {
        cur_min = nums[i];
      } else {
        left = i;
      }
    }
    for (int i = 1; i < n; i++) {
      if (nums[i] >= cur_max) {
        cur_max = nums[i];
      } else {
        right = i;
      }
    }
    return (left != -1 ? right - left + 1 : 0);
  }
};
