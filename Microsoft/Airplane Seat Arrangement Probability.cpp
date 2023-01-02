#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double nthPersonGetsNthSeat(int n) {
    // Let F(n) be the probability of the n-th person to get their seat.
    // If n=1: F(1)=1.0
    // If n=2:
    // Person 1 can pick their own seat, which has a probability of 1/2. So, now
    // person 2 gets their own seat. Or he can pick the seat of person 2, which
    // has a probability of 1/2. But, now person 2 can't get their seat. So,
    // F(2) = 0.5

    // If n=3:
    // If Person 1 picks their own seat, then all other persons
    // picks their respective seats. The probability of this is
    // (1/3)
    // Now, If person 1 picks the seat of 2 (probability (1/3)), then person 2
    // has two choices of seats which recurs back to the problem
    // where we had 2 seats and 2 persons. So this probability will be 1/2.
    // So, probability is: (1/3) * (1/2) = 1/6
    // Now, If person 1 picks the 3rd seat. then 3rd person can
    // no longer get their seat.
    // So, overall probability of 3 getting its own seat:
    // 1/3 + 1/6 = 1/2

    // In general, F(n)= 1/n + 1/n*F(n-1) + 1/n * F(n-2) + 1/n * F(n-3) + ...
    // 1/n * F(1) So, F(n)=1/n + 1/n * [F(n-1) + F(n-2) + ... F(1)] Therefore,
    // n*F(n) = F(n-1) + F(n-2) + ... F(1) --eq(1) Replacing n with n+1
    // (n+1)*F(n+1) = F(n) + F(n-1) + ... F(1). --eq(2)
    // Rewriting eq(1),
    // 0=n*F(n) - F(n-1) - F(n-2) - ... F(1)
    // Adding eq(1) and eq(2),
    // (n+1)*F(n+1) = (n+1)*F(n)
    // So, F(n) = F(n+1)
    // or F(n) = F(n-1), for n>=3
    // Base cases being: F(2)=0.5 and F(1)=1
    if (n == 1)
      return (double)1;
    else
      return (double)0.5;
  }
};
