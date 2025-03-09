#include<bits/stdc++.h>
using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
  int n=colors.size(), sz=n+k-1;
  int ans=0, alt=1, prev=colors[0];
  for(int i=1; i<sz; i++){
      alt=(prev==colors[i%n])?1:alt+1;
      if (alt>=k) ans++;
      prev=colors[i%n];
  }
  return  ans;
}

int numberOfAlternatingGroups(vector<int>& colors, int k) {
  int n = colors.size();
  int ans = 0, cnt = 0;
  for (int i = 0; i < 2*n; ++i) {
      if (i && colors[i % n] == colors[(i - 1) % n]) {
          cnt = 1;
      } else {
          ++cnt;
      }
      ans += i >= n && cnt >= k ? 1 : 0;
  }
  return ans;
}

int main()
{}