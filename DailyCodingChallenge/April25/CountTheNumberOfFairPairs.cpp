#include<bits/stdc++.h>
using namespace std;

long long countFairPairs(vector<int>& nums, int lower, int upper) {
  sort(nums.begin(), nums.end());
  return countLess(nums, upper) - countLess(nums, lower - 1);
}

long countLess(vector<int>& nums, int sum) {
  long res = 0;
  for (int i = 0, j = nums.size() - 1; i < j; ++i) {
      while (i < j && nums[i] + nums[j] > sum)
          --j;
      res += j - i;
  }
  return res;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int lower = 3;
  int upper = 6;

  long long result = countFairPairs(nums, lower, upper);
  cout << "Number of fair pairs: " << result << endl;

  return 0;
}