#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int n = (int)nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }
    if (sum % k != 0)
      return false;
    int subsetValue = sum / k;
    int subsetsFound = 0;
    bool ans = false;
    vector<int> subsets((1 << n), -1);

    // Let subsets[i]-> sum of elements in the i-th subset % subsetValue
    // So, If subsets[i]=0. means the i-th state subset has sum divisible by
    // subsetValue. Now, multile such subsets will exist and at the end if
    // substets[(1<<n)-1]=0, then true

    // Empty subset
    subsets[0] = 0;

    // For every state of elements, if that state has previously been accounted
    // for, I will mark the accountability of all possible states of elements
    // from this current state
    for (int i = 0; i < (1 << n); i++) {
      // This subset hasn't been accounted for till now.
      if (subsets[i] == -1) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        // if the j-th element is not in current subset and including it doesn't
        // ruin our subsets. Then we will say that, let's include it and also
        // mark the sum of that specific subset and mod it by subsetValue
        if (!(i & (1 << j)) && (subsets[i] + nums[j] <= subsetValue)) {
          subsets[i | (1 << j)] = (subsets[i] + nums[j]) % subsetValue;
        }
      }
    }
    return subsets[(1 << n) - 1] == 0;
  }
};
