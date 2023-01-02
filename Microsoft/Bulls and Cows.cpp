#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string getHint(string secret, string guess) {
    int n = (int)secret.size();
    vector<bool> marked(n, false);
    map<char, int> mp1;
    for (auto ch : secret) {
      mp1[ch]++;
    }
    int bulls = 0;
    int cows = 0;
    map<char, int> mp2;
    for (int i = 0; i < n; i++) {
      mp2[guess[i]]++;
      if (secret[i] == guess[i]) {
        bulls++;
        marked[i] = true;
        mp1[secret[i]]--;
        mp2[guess[i]]--;
      }
    }
    for (auto x : mp2) {
      if (mp1.count(x.first)) {
        cows += min(x.second, mp1[x.first]);
      }
    }
    string ans = to_string(bulls) + "A" + to_string(cows) + "B";
    return ans;
  }
};
