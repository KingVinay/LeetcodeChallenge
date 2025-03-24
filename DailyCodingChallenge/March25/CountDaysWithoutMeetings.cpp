#include<bits/stdc++.h>
using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
  int freeDays = 0;
  int prevEnd = 0;

  sort(meetings.begin(),meetings.end());

  for (vector<int>& meeting : meetings) {
      int start = meeting[0];
      int end = meeting[1];
      if (start > prevEnd)
          freeDays += start - prevEnd - 1;
      prevEnd = max(prevEnd, end);
  }

  return freeDays + max(0, days - prevEnd);
}

int main()
{
  int days = 10;
  vector<vector<int>> meetings = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
  cout<<countDays(days, meetings)<<endl;
  return 0;
}