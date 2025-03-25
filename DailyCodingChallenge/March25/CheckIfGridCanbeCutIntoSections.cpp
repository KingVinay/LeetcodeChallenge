#include<bits/stdc++.h>
using namespace std;

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
  vector<pair<int, int>> xs;
  vector<pair<int, int>> ys;

  for (vector<int> rectangles : rectangles) {
    int startX = rectangles[0];
    int startY = rectangles[1];
    int endX = rectangles[2];
    int endY = rectangles[3];
    
    xs.push_back({startX, endX});
    ys.push_back({startY, endY});
  }

  return max(countMerged(xs), countMerged(ys)) >= 3;
}

int countMerged(vector<pair<int, int>>& intervals) {
  int count = 0;
  int prevEnd = 0;

  ranges::sort(intervals);

  for (auto& [start, eend] : intervals)
    if (start < prevEnd) {
      prevEnd = max(prevEnd, eend);
    } else {
      prevEnd = eend;
      ++count;
    }

  return count;
}

int main()
{
  vector<vector<int>> rectangles = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
  cout << checkValidCuts(4, rectangles) << endl;
  return 0;
}