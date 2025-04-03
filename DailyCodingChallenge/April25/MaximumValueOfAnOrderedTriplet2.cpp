#include<bits/stdc++.h>
using namespace std;

// Same Solution for Triplet 1 & 2
// Most optimal solution using Time Complexity - O(n) Space Complexity - O(1)

long long maximumTripletValue(vector<int>& nums) {
  int n = nums.size();

  long long maxi = nums[0];
  long long diff = 0;
  long long res = 0;

  for(int i=1;i<n-1;i++){
      diff = max(diff, maxi - (long long)nums[i]);
      maxi = max(maxi, (long long) nums[i]);
      res = max(res, diff * (long long)nums[i+1]);
  }

  return res;
}

int main()
{
  vector<int> nums = {12, 6, 13, 1, 8};
  cout << maximumTripletValue(nums) << endl; // Output: 6
  return 0;
}