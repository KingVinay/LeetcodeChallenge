#include<bits/stdc++.h>
using namespace std;

// Using Binary Search Time - O(logn)
int maximumCount(vector<int>& nums) {
  int pos = -1, neg = -1;
  int n = nums.size();

  int s = 0, e = n-1;
  while(s<=e){
      int mid = s + (e-s)/2;
      if(nums[mid] > 0){
          pos = mid;
          e = mid - 1;
      }else{
          s = mid + 1;
      }
  } 

  s = 0, e = n-1;
  while(s<=e){
      int mid = s + (e-s)/2;
      if(nums[mid] < 0){
          neg = mid;
          s = mid + 1;
      }else{
          e = mid - 1;
      }
  }

  if(pos == -1 && neg == -1){
      return 0;
  }
  else if(pos == -1){
      return (neg+1);
  }else if(neg == -1){
      return (n-pos);
  }else{
      return max(neg+1, n-pos);
  }
  
}

// Using Single Iteration Time - O(n)
int maximumCount(vector<int>& nums) {
  int pos = 0, neg = 0;
  for(int i=0;i<nums.size();i++){
      if(nums[i] < 0){
          neg++;
      }else if(nums[i] > 0){
          pos++;
      }
  }

  return max(pos, neg);
}

int main()
{
  vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
  cout<<maximumCount(nums)<<endl;
  return 0;
}