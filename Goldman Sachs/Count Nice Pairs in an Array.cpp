#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int revNum(int n) {
    int rev = 0;
    while (n) {
      rev = rev * 10 + (n % 10);
      n /= 10;
    }
    return rev;
  }

public:
  int countNicePairs(vector<int> &nums) {
    int n = (int)nums.size();
    vector<int> rev(n), val(n);
    map<int, int> mp;
    int ans = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      rev[i] = revNum(nums[i]);
      mp[nums[i] - rev[i]]++;
    }
    for (auto x : mp) {
      ans = (ans + (x.second * 1LL * (x.second - 1)) / 2) % mod;
    }
    return ans;
  }
};
