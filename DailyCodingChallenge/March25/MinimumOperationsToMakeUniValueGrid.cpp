#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
  int m = grid.size(), n = grid[0].size();
  int mod = grid[0][0] % x;
  int nums[m * n];
  for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
          if (grid[i][j] % x != mod) {
              return -1;
          }
          nums[i * n + j] = grid[i][j];
      }
  }
  sort(nums, nums + m * n);
  int mid = nums[(m * n)/2];
  int ans = 0;
  for (int v : nums) {
      ans += abs(v - mid) / x;
  }
  return ans;
}

int main()
{
  vector<vector<int>> grid = {{5,1,3},{9,3,1},{1,3,9}};
  int x = 2;
  cout<<minOperations(grid, x)<<endl;
  return 0;
}