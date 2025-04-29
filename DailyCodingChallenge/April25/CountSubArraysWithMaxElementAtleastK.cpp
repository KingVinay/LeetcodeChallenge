#include<bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
  int mx = *max_element(nums.begin(),nums.end());
  int countk = 0,n = nums.size();

  long long ans = 0;

  for(int l=0,r=0;r<n;r++){
      if(nums[r] == mx){
          countk++;
      }

      while(countk >= k){
          if(nums[l++] == mx){
              countk--;
          }
          ans += n-r;
      }

  }

  return ans;

}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 2;
  long long result = countSubarrays(nums, k);
  cout << "The number of subarrays with max count " << k << " is: " << result << endl;
  return 0;
}