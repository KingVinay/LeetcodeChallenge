#include<bits/stdc++.h>
using namespace std;

vector<int> applyOperations(vector<int>& nums) {
  int n = nums.size();

  for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i + 1]) {
          nums[i] *= 2;
          nums[i + 1] = 0;
      }
  }

  int zi = 0;
  for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
          swap(nums[zi], nums[i]);
          zi++;
      }
  }

  return nums;
}

int main()
{
  vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
  vector<int> result = applyOperations(nums);
  for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
  }
  return 0;
}