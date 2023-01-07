#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int n = (int)points.size();
    if (n == 1)
      return 1;
    /*
    Let's select the first point as our origin.
    From that point, we select other points and calculate the slope.
    Now, we increase count of this slope.
    Get the maximum of count of all slopes for every origin point.
    */
    int ans = 2;
    for (int i = 0; i < n; i++) {
      map<double, int> mp;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        double slope =
            atan2(points[j][1] - points[i][1], points[j][0] - points[i][0]);
        mp[slope]++;
      }
      for (auto slope : mp) {
        ans = max(ans, slope.second + 1);
      }
    }
    return ans;
  }
};
