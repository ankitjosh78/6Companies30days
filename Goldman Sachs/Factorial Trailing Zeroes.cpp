#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    // Zero can only be produced by 2 and 5
    // So, if we calculate number of 5's in n! and 2's in n!, we are done.
    // We can see that number of 5's is always less than or equal number to
    // number of 2's Now, how to find number of 5's in n! I can't compute n! as
    // it can be very very big. Let's see, divide n/5, we get number of 5's in
    // upto range of n like n=10 n!= 10 * 9 * 8 * 7 * 6 * 5 * 4* 3* 2 * 1 now,
    // 10/5=2 which means I have two multiples of 5 now let's say I have 25 this
    // has more than two 5 but will be counted once under n/5 So, we can take
    // n/25 Similary, n/125 and so on...
    int ans = 0;
    int val = 5;
    while ((n / val) > 0) {
      ans += (n / val);
      val *= 5;
    }
    return ans;
  }
};
