#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    /*
    Approach:
    My goal is to pick among all the available the stock, the one
    which provides the maximum profit.
    So, let's sort the stocks in increasing order of capital.
    After some index i, we can no longer buys stocks with current capital
    Now, till that index i, all previous elements we can access.
    So, among these stocks, I want the maximum one. I also want to delete it
    after one operation.
    */
    int n = (int)profits.size();
    // Storing profits and capitals of stocks together
    vector<pair<int, int>> stocks(n);
    priority_queue<int> pq;
    int noLongerBuy = 0;
    for (int i = 0; i < n; i++) {
      stocks[i] = {capital[i], profits[i]};
    }
    // Sorting them as per capital
    sort(stocks.begin(), stocks.end());

    // Since I need to take k stocks
    for (int i = 0; i < k; i++) {
      // Keeping track of the first stock from which I can no longer buy
      while (noLongerBuy < n && stocks[noLongerBuy].first <= w) {
        pq.push(stocks[noLongerBuy++].second);
      }
      if (pq.size() == 0) {
        break;
      }
      // Adding profit of stock and removing it
      w += pq.top();
      pq.pop();
    }
    return w;
  }
};
