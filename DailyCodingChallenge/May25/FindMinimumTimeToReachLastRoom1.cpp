#include<bits/stdc++.h>
using namespace std;

int minTimeToReach(vector<vector<int>>& moveTime) {
  return dijkstra(moveTime, {0, 0},
                  {moveTime.size() - 1, moveTime[0].size() - 1});
}

int dijkstra(vector<vector<int>>& moveTime, pair<int, int> src,
           pair<int, int> dst) {
  int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int m = moveTime.size();
  int n = moveTime[0].size();
  vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

  dist[0][0] = 0;
  using T = pair<int, pair<int, int>>;
  priority_queue<T, vector<T>, greater<>> minHeap;
  minHeap.push({dist[0][0], src});

  while (!minHeap.empty()) {
      auto [d, u] = minHeap.top();
      minHeap.pop();
      if (u == dst)
          return d;
      auto [i, j] = u;
      if (d > dist[i][j])
          continue;
      for (auto& [dx, dy] : kDirs) {
          int x = i + dx;
          int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
              continue;
          int newDist = max(moveTime[x][y], d) + 1;
          if (newDist < dist[x][y]) {
              dist[x][y] = newDist;
              minHeap.push({newDist, {x, y}});
          }
      }
  }

  return -1;
}

int main()
{
  vector<vector<int>> moveTime = {
      {0, 1, 2},
      {1, 2, 3},
      {2, 3, 4}
  };

  int result = minTimeToReach(moveTime);
  cout << "Minimum time to reach the last room: " << result << endl;

  return 0;
}