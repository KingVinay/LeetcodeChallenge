#include<bits/stdc++.h>
using namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2) {
  long sum1 = accumulate(nums1.begin(), nums1.end(), 0L);
  long sum2 = accumulate(nums2.begin(), nums2.end(), 0L);
  int zero1 = ranges::count(nums1, 0);
  int zero2 = ranges::count(nums2, 0);
  if (zero1 == 0 && sum1 < sum2 + zero2)
      return -1;
  if (zero2 == 0 && sum2 < sum1 + zero1)
      return -1;
  return max(sum1 + zero1, sum2 + zero2);
}

int main()
{
  vector<int> nums1 = {1, 2, 0};
  vector<int> nums2 = {3, 4, 0};
  cout << minSum(nums1, nums2) << endl; // Output: 10
  return 0;
}