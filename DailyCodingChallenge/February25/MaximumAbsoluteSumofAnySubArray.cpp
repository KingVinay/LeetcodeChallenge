#include<bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
  int ans1 = INT_MIN,ans2 = INT_MIN;
  int cs1 = 0, cs2 = 0;
  for(int i=0;i<nums.size();i++){
      cs1 += nums[i];
      ans1 = max(cs1, ans1);
      if(cs1 < 0){
          cs1 = 0;
      }

      cs2 += nums[i]*-1;
      ans2 = max(cs2,ans2);
      if(cs2<0){
          cs2 = 0;
      }
  }

  return max(ans1,ans2);
}

int main()
{
  vector<int> nums = {1,-3,2,3,-4};
  cout << maxAbsoluteSum(nums) << endl;
  return 0;
}