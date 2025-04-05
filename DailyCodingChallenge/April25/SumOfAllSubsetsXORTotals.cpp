#include<bits/stdc++.h>
using namespace std;

int subsetXORSum(vector<int>& nums) { return dfs(nums, 0, 0); }
    
int dfs(vector<int>& nums, int i, int xors) {
  if (i == nums.size())
        return xors;

  int x = dfs(nums, i + 1, xors);
  int y = dfs(nums, i + 1, nums[i] ^ xors);
  return x + y;
}

int main()
{
  vector<int> nums = {1, 2, 3};
  cout << subsetXORSum(nums) << endl; // Output: 6
  return 0;
}