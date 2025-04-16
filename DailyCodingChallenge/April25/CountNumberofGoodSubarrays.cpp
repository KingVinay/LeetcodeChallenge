#include<bits/stdc++.h>
using namespace std;

long long countGood(vector<int>& nums, int k) {
  long ans = 0;
  int pairs = 0;
  unordered_map<int, int> count;

  for (int l = 0, r = 0; r < nums.size(); ++r) {
      pairs += count[nums[r]]++;
      while (pairs >= k)
          pairs -= --count[nums[l++]];
      ans += l;
  }

  return ans;
}

int main()
{
  vector<int> nums = {3,1,4,3,2,2,4};
  int k = 2;

  long long result = countGood(nums, k);
  cout << "Number of good subarrays: " << result << endl;

  return 0;
}