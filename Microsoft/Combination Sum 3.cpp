#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<int>> answer;
  void dfsHelper(int k, int n, int lastPicked,
                 vector<int> &currentCombination) {
    if (n == 0) {
      if (k == 0)
        answer.push_back(currentCombination);
      return;
    }
    for (int number = lastPicked + 1; number <= 9; number++) {
      if (n - number >= 0) {
        currentCombination.push_back(number);
        dfsHelper(k - 1, n - number, number, currentCombination);
        currentCombination.pop_back();
      } else {
        break;
      }
    }
    return;
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> currentCombination;
    dfsHelper(k, n, 0, currentCombination);
    return answer;
  }
};
