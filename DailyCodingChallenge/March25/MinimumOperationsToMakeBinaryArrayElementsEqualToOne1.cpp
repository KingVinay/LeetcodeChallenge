#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
  int ans = 0, n = nums.size();
  for(int i=0;i<n-2;i++){
      if(nums[i] == 0){
          nums[i+1] ^= 1;
          nums[i+2] ^= 1;
          ans++;
      }
  }

  return (nums[n-1] == 0 || nums[n-2] == 0) ? -1 : ans;
}

int main()
{
    vector<int> nums = {1,0,0,1,0,1,1,0};
    cout<<minOperations(nums)<<endl;
    return 0;
}