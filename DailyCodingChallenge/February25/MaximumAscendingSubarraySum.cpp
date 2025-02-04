#include<bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int>& nums) {
    int ans = 0,temp = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i-1] < nums[i]){
            temp += nums[i];
        }else{
            ans = max(ans,temp);
            temp = nums[i];
        }
    }
    
    ans = max(ans,temp);
    return ans;
}

int main()
{
  vector<int> nums = {10, 20, 30, 5, 10, 50};
  cout << "The maximum ascending subarray sum is " << maxAscendingSum(nums) << endl;

  return 0;
}