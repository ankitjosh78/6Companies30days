#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    int n = (int)nums.size();
    // Sum of elements
    long long sum = 0;
    // Initial sequence
    long long init = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      init += (long long)i * nums[i];
    }
    // Final Answer
    long long ans = init;

    // Every next rotation F(i)=F(i-1) + S - (n * nums[n-i])
    for (int i = 1; i < n; i++) {
      init = init + sum - n * nums[n - i];
      ans = max(ans, init);
    }
    return ans;
  }
};
