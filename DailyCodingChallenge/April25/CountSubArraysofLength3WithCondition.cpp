#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& nums) {
  int ans = 0,i=0;
  for(int j=2;j<nums.size();j++){
      float check1 = nums[i] + nums[j];
      float check2 = nums[i+1]/2.0;

      if(check1 == check2){
          ans++;
      }
      i++;
  }
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int result = countSubarrays(nums);
  cout << "The number of subarrays of length 3 with the given condition is: " << result << endl;
  return 0;
}