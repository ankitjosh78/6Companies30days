#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    // Left Boundary: first index from left such that a[i] > a[j..] (j>i)
    // Right Boundary: first indext from right such that a[i] > a[j...] (j>i)

    int n = (int)nums.size();
    int left = -1, right = n;
    int cur_min = nums[n - 1], cur_max = nums[0];

    // Let cur_min be the current minimum i have seen till now from the right.
    // Then, moving towards left, If I get a value which is bigger than my
    // cur_min, that index becomes the starting point of the subarray I should
    // sort.

    // Similary, let cur_max be the current maximum i have seen till now from
    // the left. Then moving towards right, if I get a value which is smaller
    // than my cur_max, that index becomes the ending point of the subarray I
    // should sort.

    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] <= cur_min) {
        cur_min = nums[i];
      } else {
        left = i;
      }
    }
    for (int i = 1; i < n; i++) {
      if (nums[i] >= cur_max) {
        cur_max = nums[i];
      } else {
        right = i;
      }
    }

    // Now, if leftBoundary is not -1, meaning there is some index for which
    // a[i] > cur_min(i+1..n-1)
    // This obviously means that there will be some index for which a[i] <
    // cur_max(0...i-1)

    return (left != -1 ? right - left + 1 : 0);
  }
};
