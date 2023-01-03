#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pli pair<ll, ll>

class Solution {
private:
  vector<pli> *adj;
  vector<ll> timeTo;
  vector<ll> numberOfWays;
  const ll mod = 1e9 + 7;
  ll modAdd(ll a, ll b, ll m) { return ((a % m) + (b % m) + m) % m; }

public:
  int countPaths(int n, vector<vector<int>> &roads) {
    adj = new vector<pli>[n];
    timeTo.resize(n, LONG_MAX);
    numberOfWays.resize(n, 0);
    for (auto road : roads) {
      adj[road[0]].push_back({road[1], road[2]});
      adj[road[1]].push_back({road[0], road[2]});
    }

    // Using Dijkstra's algorithm to find the shortest path from a single
    // source.

    timeTo[0] = 0;
    numberOfWays[0] = 1;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0LL, 0});

    while (!pq.empty()) {
      ll curNode = pq.top().second;
      ll curNodeTime = pq.top().first;
      pq.pop();

      for (auto edge : adj[curNode]) {
        ll nextNode = edge.first;
        ll nextNodeTime = edge.second;

        // If current distance is smaller, then update number of ways to reach
        // here as number of ways to reach previous node.
        if (curNodeTime + nextNodeTime < timeTo[nextNode]) {
          timeTo[nextNode] = curNodeTime + nextNodeTime;
          numberOfWays[nextNode] = (numberOfWays[curNode] % mod);
          pq.push({timeTo[nextNode], nextNode});
        }

        // If current distance is same as the shortest distance, then add number
        // of ways to reach previous node to the answer
        else if (curNodeTime + nextNodeTime == timeTo[nextNode]) {
          numberOfWays[nextNode] =
              modAdd(numberOfWays[nextNode], numberOfWays[curNode], mod);
        }
      }
    }
    return numberOfWays[n - 1];
  }
};
