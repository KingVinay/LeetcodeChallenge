#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& nums, int k, int cap){
  int count = 0;
  int prev = -2;

  for(int i=0;i<nums.size();i++){
      if(nums[i] > cap || i == prev + 1){
          continue;
      }
      count++;
      prev = i;
  }

  return count >= k;
}

int minCapability(vector<int>& nums, int k) {
  int left = 1, right = *max_element(nums.begin(),nums.end());
  while(left < right){
      int mid = (left + right)/2;
      if(check(nums, k, mid)){
          right = mid;
      }else{
          left = mid + 1;
      }
  }

  return left;
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    cout<<minCapability(nums, k)<<endl;
    return 0;
}