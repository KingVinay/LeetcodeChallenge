#include<bits/stdc++.h>
using namespace std;

int sumdigits(int num){
  int sum = 0;
  while(num!=0){
    sum += num%10;
    num/=10;
  }
  return sum;
}

//Using Vector (10^9 limit having 9*9 max sum) in Time-O(n) 
int maximumSum(vector<int>& nums) {
  vector<int> sameDigit(82, -1);
  int sum, maxSum=-1;
  for(int i=0; i<nums.size(); i++) {
    sum=sumdigits(nums[i]);
    if(sameDigit[sum]!=-1) {
      maxSum=max(maxSum, sameDigit[sum]+nums[i]);
      sameDigit[sum]=max(sameDigit[sum], nums[i]);
    } else {
      sameDigit[sum]=nums[i];
    }
  }
  return maxSum;
}

// Using Unordered Map in Time - O(n*k)

int maximumSum(vector<int>& nums) {
  unordered_map<int,int> mp;
  int ans = -1;
  for(int i=0;i<nums.size();i++){
      int s = sumdigits(nums[i]);
      if(mp.find(s)!= mp.end()){
          ans = max(ans,mp[s]+nums[i]);
          mp[s] = max(mp[s],nums[i]);
      }else{
          mp[s] = nums[i];
      }
  }

  return ans;
}

int main()
{
  vector<int> nums = {18,43,36,13,27,34};
  cout << maximumSum(nums) << endl;
  return 0;
}