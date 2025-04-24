#include<bits/stdc++.h>
using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
  int kMax = 2000;
  int totalDistinct = unordered_set<int>(nums.begin(), nums.end()).size();
  int ans = 0;
  int distinct = 0;
  vector<int> count(kMax + 1);

  int l = 0;
  for (int num : nums) {
      if (++count[num] == 1)
          ++distinct;
      while (distinct == totalDistinct)
          if (--count[nums[l++]] == 0)
              --distinct;
      ans += l;
  }

  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 2, 3, 1, 2};
  int result = countCompleteSubarrays(nums);
  cout << "The number of complete subarrays is: " << result << endl;
  return 0;
}