#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int gcd(int a, int b) { return (!b ? a : gcd(b, a % b)); }

  int minOperations(vector<int> &nums, vector<int> &numsDivide) {
    int targetGcd = numsDivide[0];
    for (int i = 0; i < (int)numsDivide.size() - 1; i++) {
      targetGcd = gcd(targetGcd, gcd(numsDivide[i], numsDivide[i + 1]));
    }
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size(); i++) {
      if (targetGcd % nums[i] == 0) {
        return ans;
      } else {
        ans++;
      }
    }
    return -1;
  }
}
