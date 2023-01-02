#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> *adj;
  vector<int> color;
  bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
      if (color[u] == 0) {
        if (dfs(u)) {
          return true;
        }
      } else if (color[u] == 1) {
        return true;
      }
    }
    color[v] = 2;
    return false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    if (prerequisites.size() == 0) {
      return true;
    }
    adj = new vector<int>[numCourses];
    color.resize(numCourses, 0);
    for (auto needs : prerequisites) {
      adj[needs[0]].push_back(needs[1]);
    }
    for (int i = 0; i < numCourses; i++) {
      if (color[i] == 0 && dfs(i)) {
        return false;
      }
    }
    return true;
  }
};
