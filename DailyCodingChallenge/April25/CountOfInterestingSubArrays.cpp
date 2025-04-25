#include<bits/stdc++.h>
using namespace std;

long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
  long long ans = 0;
  int prefix = 0;
  unordered_map<int, int> prefixCount{{0, 1}};

  for (const int num : nums) {
      if (num % modulo == k)
          prefix = (prefix + 1) % modulo;
      ans += prefixCount[(prefix - k + modulo) % modulo];
      ++prefixCount[prefix];
  }

  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int modulo = 2;
  int k = 1;
  long long result = countInterestingSubarrays(nums, modulo, k);
  cout << "The number of interesting subarrays is: " << result << endl;
  return 0;
}