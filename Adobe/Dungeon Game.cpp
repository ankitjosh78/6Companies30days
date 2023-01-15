#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int n = (int)dungeon.size();
    int m = (int)dungeon[0].size();
    // State: dp[i][j]-> min health needed to go from (i,j) to (n-1,m-1)
    // Transition: dp[i][j]= max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j],1)
    // Base Case: dp[n-1][m-1]=max(1, 1 - dungeon[n-1][m-1])
    // Final Answer: dp[0][0]
    int dp[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = 1e9;
      }
    }
    dp[n - 1][m - 1] =
        (dungeon[n - 1][m - 1] <= 0 ? abs(dungeon[n - 1][m - 1]) + 1 : 1);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (i + 1 < n) {
          dp[i][j] = min(dp[i][j], max(dp[i + 1][j] - dungeon[i][j], 1));
        }
        if (j + 1 < m) {
          dp[i][j] = min(dp[i][j], max(dp[i][j + 1] - dungeon[i][j], 1));
        }
      }
    }
    return dp[0][0];
  }
};
