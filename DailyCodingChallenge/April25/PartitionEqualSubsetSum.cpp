#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
  int sum = reduce(nums.begin(), nums.end());
  if (sum & 1) return false;
  sum /= 2;
  vector<bool> dp(sum + 1, false);
  dp[0] = true;
  for (auto num : nums) {
      for (int j = sum; j >= num; j--) {
          if (dp[j - num]) dp[j] = true;
      }
  }

  return dp[sum];
}

int main()
{
  vector<int> nums = {1, 5, 11, 5};
  if (canPartition(nums)) {
      cout << "Can partition into two subsets with equal sum." << endl;
  } else {
      cout << "Cannot partition into two subsets with equal sum." << endl;
  }

  return 0;
}