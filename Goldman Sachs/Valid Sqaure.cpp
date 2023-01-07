#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int getDistance(vector<int> &p1, vector<int> &p2) {
    return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
  }

public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    // For a squaure, from a point distance(a) to 2 points will be same
    // and distance to another point will be sqrt(2)*a.
    // Let's pick point p1 as starting and calculate distances accordingly.

    int d2 = getDistance(p1, p2);
    int d3 = getDistance(p1, p3);
    int d4 = getDistance(p1, p4);
    // If we have the same point, then it can't be a square
    if (d2 == 0 || d3 == 0 || d4 == 0)
      return false;

    // If two points are at same distance from a point then we need to check
    // if the fourth point is the diagonal, also we need to check
    // if all the points lie on the same side. for that we can take distance
    // from the fourth point and do another check on all the other points.

    if (d2 == d3 && 2 * d2 == d4 &&
        getDistance(p2, p3) == 2 * getDistance(p3, p4)) {
      return true;
    }
    if (d2 == d4 && 2 * d2 == d3 &&
        getDistance(p2, p4) == 2 * getDistance(p3, p4)) {
      return true;
    }
    if (d3 == d4 && 2 * d3 == d2 &&
        getDistance(p3, p4) == 2 * getDistance(p2, p4)) {
      return true;
    }
    return false;
  }
};
