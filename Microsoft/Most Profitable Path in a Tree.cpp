#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
  int nodes;
  vector<int> *adj;
  vector<int> amount;

  Graph(int nodes, vector<int> amount) {
    // Initialising the graph class
    this->nodes = nodes;
    adj = new vector<int>[this->nodes];
    this->amount = amount;
  }

  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  map<int, int> getShortestPath(int u, int v) {
    vector<bool> vis(nodes, false);
    vector<int> entry(nodes, -1);
    vector<int> parent(nodes);

    // Using BFS to find the shortest path from bob to root.
    queue<int> pendingNodes;
    parent[u] = -1;
    pendingNodes.push(u);
    vis[u] = true;
    entry[u] = 0;
    int time = 0;

    while (pendingNodes.size() != 0) {
      int pendingNodesLen = pendingNodes.size();
      while (pendingNodesLen--) {
        int curNode = pendingNodes.front();
        pendingNodes.pop();
        for (int nextNode : adj[curNode]) {
          if (!vis[nextNode]) {
            vis[nextNode] = true;
            pendingNodes.push(nextNode);
            parent[nextNode] = curNode;
            entry[nextNode] = entry[curNode] + 1;
          }
        }
      }
      time++;
    }
    map<int, int> path;
    for (int dest = v; dest != -1; dest = parent[dest]) {
      path[dest] = entry[dest];
    }
    return path;
  }

  int maxProfit(int u, int par, int time, map<int, int> &entry) {
    int val = 0;
    // Worst possible profit
    int ans = -1e9 - 5;

    // Getting the correct value from this node as per path of bob
    if (entry.count(u)) {
      if (time < entry[u]) {
        val = amount[u];
      } else if (time == entry[u]) {
        val = amount[u] / 2;
      }
    } else {
      val = amount[u];
    }

    // Calculating the profit for subsequent children
    for (int v : adj[u]) {
      if (v == par)
        continue;
      ans = max(ans, maxProfit(v, u, time + 1, entry));
    }
    // If we are at a leaf node
    if (ans <= -1e9 - 5) {
      ans = 0;
    }
    return val += ans;
  }
};

class Solution {
public:
  int mostProfitablePath(vector<vector<int>> &edges, int bob,
                         vector<int> &amount) {
    int n = edges.size() + 1;
    Graph g(n, amount);
    for (auto conn : edges) {
      g.add_edge(conn[0], conn[1]);
    }
    map<int, int> shortestPath = g.getShortestPath(bob, 0);
    int ans = g.maxProfit(0, -1, 0, shortestPath);
    return ans;
  }
};
