#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumCardPickup(vector<int> &cards) {
    /*
    Approach:
    * I want to find two duplicates which are as close as possible.
    * So, on finding first duplicate we can get our first answer and then we
      update location of the element we just found

    * We can use a hashmap for storing the locations of each element
    */
    int n = (int)cards.size();
    map<int, int> mp;
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
      if (mp.count(cards[i])) {
        ans = min(ans, i - mp[cards[i]] + 1);
      }
      mp[cards[i]] = i;
    }
    return (ans != n + 1 ? ans : -1);
  }
};
