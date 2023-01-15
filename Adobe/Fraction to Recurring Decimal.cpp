#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";
    string ans = "";
    // If final fraction has negative sign
    if (numerator < 0 ^ denominator < 0) {
      ans += "-";
    }
    // converting everything to long long
    long long nu = labs(numerator), de = labs(denominator);
    long long quotient = nu / de;
    long long remainder = nu % de;

    // adding the initial quotient
    ans += to_string(quotient);
    // if multiple, return ans;
    if (remainder == 0)
      return ans;
    // else add decimal point.
    ans += ".";

    // using map for keeping track of remainders found.
    map<long long, int> mp;
    // keep looping until we get a proper fraction or recurring fraction
    while (remainder != 0) {
      // if remainder found previously then add '(' and ')' at appropriate
      // positions.
      if (mp.count(remainder)) {
        ans.insert((ans.begin() + mp[remainder] - ans.begin()), "(");
        ans += ")";
        return ans;
      }
      // if new remainder then mark its entry point and do normal division
      else {
        mp[remainder] = (int)ans.size();
        remainder *= 10;
        quotient = remainder / de;
        remainder = remainder % de;
        ans += to_string(quotient);
      }
    }
    return ans;
  }
};
