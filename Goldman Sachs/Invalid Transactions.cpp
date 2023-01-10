#include <bits/stdc++.h>
using namespace std;

// Making a class of Transaction data type
class Transaction {
public:
  string name;
  string city;
  int amount;
  int time;
  int id;
  bool marked = false;

  Transaction(string name, string city, int amount, int time, int id) {
    this->name = name;
    this->city = city;
    this->amount = amount;
    this->time = time;
    this->id = id;
  }
};
class Solution {
public:
  vector<string> invalidTransactions(vector<string> &transactions) {
    int n = (int)transactions.size();
    if (n == 0)
      return {};
    map<string, vector<Transaction>> mp;
    map<int, bool> marked;
    for (int i = 0; i < n; i++) {
      string currentTrans = transactions[i];
      int m = currentTrans.size();
      string name = "";
      int j = 0;
      for (; j < m; j++) {
        if (currentTrans[j] != ',') {
          name.push_back(currentTrans[j]);
        } else
          break;
      }
      j++;
      string timeTaken = "";
      for (; j < m; j++) {
        if (currentTrans[j] != ',') {
          timeTaken.push_back(currentTrans[j]);
        } else
          break;
      }
      j++;
      int time = stoi(timeTaken);
      string amountTaken = "";
      for (; j < m; j++) {
        if (currentTrans[j] != ',') {
          amountTaken.push_back(currentTrans[j]);
        } else
          break;
      }
      j++;
      int amount = stoi(amountTaken);
      string city = "";
      for (; j < m; j++) {
        if (currentTrans[j] != ',') {
          city.push_back(currentTrans[j]);
        } else
          break;
      }
      Transaction T(name, city, amount, time, i);
      mp[name].push_back(T);
    }
    for (auto x : mp) {
      string currentName = x.first;
      for (auto y : mp[currentName]) {
        if (y.amount > 1000)
          marked[y.id] = true;
        for (auto z : mp[currentName]) {
          if (y.city == z.city)
            continue;
          if (abs(y.time - z.time) <= 60) {
            marked[y.id] = marked[z.id] = true;
          }
        }
      }
    }
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      if (marked[i]) {
        ans.push_back(transactions[i]);
      }
    }
    return ans;
  }
};
