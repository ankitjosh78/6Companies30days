#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    int n = (int)nums.size();
    // Now, what do I need?
    // nums[i] < nums[j] < nums[k], (i<j<k)
    // Let's say I have some k.
    // Then for that, I would have an j such that nums[j] < nums[k].
    // That's easy to keep track of.
    // Now, I also need to keep track of some i, such that nums[i]< nums[j].
    // So, I can find the minimum and 2nd minimum till every k
    long long first_min = 1e18, second_min = 1e18;
    for (int i = 0; i < n; i++) {
      if (nums[i] > second_min)
        return true;
      if (nums[i] > first_min)
        second_min = min(second_min, nums[i] * 1LL);
      first_min = min(first_min, nums[i] * 1LL);
    }
    return false;
  }
};
