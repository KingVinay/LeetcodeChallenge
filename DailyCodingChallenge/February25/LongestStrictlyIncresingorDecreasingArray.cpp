#include<bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
    int dec = 1,inc = 1;
    int ans = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1] < nums[i]){
            inc++;
            dec = 1;
        }else if(nums[i-1] > nums[i]){
            dec++;
            inc = 1;
        }else{
            inc = 1;
            dec = 1;
        }

        ans = max(ans,max(inc,dec));
    }
    return ans;
}

int main()
{
  vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
  cout << "The length of the longest strictly increasing or decreasing subarray is " << longestMonotonicSubarray(nums) << endl;

  return 0;
}