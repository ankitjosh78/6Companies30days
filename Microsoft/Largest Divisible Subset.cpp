#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    /*
     * State: dp[i]-> size of largest subset ending at index i such that i-th
       value is max.
     * Transition: dp[i]: if(a_i % a_j ==0 && dp[i]<=dp[j])
                   dp[i]=1+dp[j];
     * Base Case: dp[0]=1
     * Final Answer: dp[n-1]
     */
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());
    int dp[n];
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
      dp[i] = 1;
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if ((nums[i] % nums[j] == 0) && (dp[i] <= dp[j])) {
          dp[i] = dp[j] + 1;
          ans[i] = j;
        }
      }
    }
    vector<int> res;
    int largest_subset_index = max_element(dp, dp + n) - dp;
    for (int i = largest_subset_index; i != -1; i = ans[i]) {
      res.push_back(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
