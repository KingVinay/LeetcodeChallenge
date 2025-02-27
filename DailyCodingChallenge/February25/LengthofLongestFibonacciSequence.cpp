#include<bits/stdc++.h>
using namespace std;

int lenLongestFibSubseq(vector<int>& arr) {
  unordered_map<int, int> indexMap;
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
      indexMap[arr[i]] = i;
  }

  vector<vector<int>> dp(n, vector<int>(n, 2));
  int maxLength = 0;

  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
          int prevNum = arr[i] - arr[j];
          if (indexMap.count(prevNum)) {
              int k = indexMap[prevNum];
              if (k < j) {
                  dp[j][i] = max(dp[j][i], dp[k][j] + 1);
                  maxLength = max(maxLength, dp[j][i]);
              }
          }
      }
  }

  return maxLength > 2 ? maxLength : 0;
}

int main()
{
  vector<int> arr = {1, 3, 7, 11, 12, 14, 18};
  cout << lenLongestFibSubseq(arr) << endl;
  return 0;
}