#include<bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
  long ans = 0;
  int j = -1;
  int prevMinKIndex = -1;
  int prevMaxKIndex = -1;

  for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < minK || nums[i] > maxK)
          j = i;
      if (nums[i] == minK)
          prevMinKIndex = i;
      if (nums[i] == maxK)
          prevMaxKIndex = i;

      ans += max(0, min(prevMinKIndex, prevMaxKIndex) - j);
  }

  return ans;
}

int main()
{
  vector<int> nums = {1, 3, 5, 2, 7, 5};
  int minK = 1;
  int maxK = 5;
  long long result = countSubarrays(nums, minK, maxK);
  cout << "The number of subarrays with fixed bounds is: " << result << endl;
  return 0;
}