#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    set<string> s = {"+", "-", "*", "/"};
    stack<string> st;
    int res;
    for (auto op : tokens) {
      if (s.count(op)) {
        int secondOperand = stoi(st.top());
        st.pop();
        int firstOperand = stoi(st.top());
        st.pop();
        res = 0;
        if (op == "+") {
          res = (firstOperand + secondOperand);
        } else if (op == "-") {
          res = (firstOperand - secondOperand);
        } else if (op == "*") {
          res = (firstOperand * secondOperand);
        } else {
          res = (firstOperand / secondOperand);
        }
        st.push(to_string(res));
      } else {
        st.push(op);
      }
    }
    return stoi(st.top());
  }
};
