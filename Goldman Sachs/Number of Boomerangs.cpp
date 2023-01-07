#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int getDistance(vector<int> &p1, vector<int> &p2) {
    return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
  }

public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int n = (int)points.size();
    int ans = 0;
    /*
    My goal is to select an i. From there i'm looking for (j,k) such that
    distance of i from both j and k are same.

    For a fixed i, I can its distances to all the points.
    Now, all that's left is for a specific distance, couting the number of pairs
    (j,k) possible (ordering also matters)
    */
    for (int i = 0; i < n; i++) {
      map<int, int> mp;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        int curDist = getDistance(points[i], points[j]);
        ++mp[curDist];
      }
      for (auto dist : mp) {
        ans += (dist.second * 1LL * (dist.second - 1));
      }
    }
    return ans;
  }
};
