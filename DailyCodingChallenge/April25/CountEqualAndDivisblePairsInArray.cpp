#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int k) {
  int res = 0, n = nums.size();
  for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
          if (nums[i] == nums[j] && (i * j) % k == 0) res++;
      }
  }
  return res;
}

int main()
{
  vector<int> nums = {1, 2, 3, 1, 2, 3};
  int k = 2;

  int result = countPairs(nums, k);
  cout << "Number of equal and divisible pairs: " << result << endl;

  return 0;
}