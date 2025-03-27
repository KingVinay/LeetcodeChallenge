#include<bits/stdc++.h>
using namespace std;

int minimumIndex(vector<int>& nums) {
  int n = nums.size();
  unordered_map<int, int> count1;
  unordered_map<int, int> count2;

  for (int num : nums)
      ++count2[num];

  for (int i = 0; i < n; ++i) {
      int freq1 = ++count1[nums[i]];
      int freq2 = --count2[nums[i]];
      if (freq1 * 2 > i + 1 && freq2 * 2 > n - 1 - i)
          return i;
  }

  return -1;
}

int main()
{
  vector<int> nums = {1,2,3,4,5};
  cout<<minimumIndex(nums)<<endl;
  return 0;
}