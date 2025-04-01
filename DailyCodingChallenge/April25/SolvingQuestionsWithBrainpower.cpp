#include<bits/stdc++.h>
using namespace std;

// Using Dynamic Programming in O(n) time complexity
long long mostPoints(vector<vector<int>>& questions) {
  int n = questions.size();
  vector<long long> dp(n+1,0);

  for(int i=n-1;i>=0;i--){
      int nextidx = i + questions[i][1] + 1;
      long long currpoints = questions[i][0] + (nextidx < n ? dp[nextidx] : 0);
      long long maxpoints = dp[i+1];

      dp[i] = max(currpoints,maxpoints);
  }

  return dp[0];
}

// Using Brute Force in O(n^2) time complexity
long long mostPoints(vector<vector<int>>& questions) {
  long long ans = 0;
  int n = questions.size();
  for(int i=0;i<n;i++){
      int j = i;
      long long temp = 0;
      while(j<n){
          temp += questions[j][0];
          j += questions[j][1] + 1;
      }

      ans = max(temp,ans);
  }

  return ans;
}

int main()
{
  vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
  cout << mostPoints(questions) << endl; // Output: 7
  return 0;
}