#include<bits/stdc++.h>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
  int i = 0, j = 1;
  long sum = nums[i];
  int ans = 1;

  while (j < nums.size()) {
      while ((sum & nums[j]) != 0) {
          sum ^= nums[i];
          i++;
      }
      sum |= nums[j];
      ans = max(ans, j-i+1);
      j++;
  }

  return ans;
}

int main()
{}