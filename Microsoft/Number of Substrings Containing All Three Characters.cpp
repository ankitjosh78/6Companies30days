#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    /*
      When we get a window(l,r) where all 3 distinct characters are present.
      We can say that for every r in range(r,n-1) all other substrings will also
      be valid.
      Hence we add (n-r) to our answer, remove the left character and
      push our left boundary
    */
    int n = (int)s.size();
    map<char, int> mp;
    int left = 0, right = 0;
    int ans = 0;
    while (right < n) {
      mp[s[right]]++;
      while (mp.size() == 3) {
        ans += n - right;
        mp[s[left]]--;
        if (mp[s[left]] == 0) {
          mp.erase(s[left]);
        }
        left++;
      }
      right++;
    }
    return ans;
  }
};
