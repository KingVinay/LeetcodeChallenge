#include<bits/stdc++.h>
using namespace std;

int maxEvents(vector<vector<int>>& events) {
  int ans = 0;
  int d = 0;
  int i = 0;
  priority_queue<int, vector<int>, greater<>> minHeap;

  ranges::sort(events);

  while (!minHeap.empty() || i < events.size()) {
      if (minHeap.empty())
          d = events[i][0];

      while (i < events.size() && events[i][0] == d)
          minHeap.push(events[i++][1]);
      minHeap.pop();
      ++ans;
      ++d;
      while (!minHeap.empty() && minHeap.top() < d)
          minHeap.pop();
  }

  return ans;
}

int main()
{
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    int result = maxEvents(events);
    cout << "Maximum number of events that can be attended: " << result << endl; // Output: 4
    return 0;
}