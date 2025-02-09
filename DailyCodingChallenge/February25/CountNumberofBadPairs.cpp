#include<bits/stdc++.h>
using namespace std;

// Using
long long countBadPairs(vector<int>& nums) {
  long long ans = 0;
  unordered_map<int,int> diff;
  unordered_map<int,int> count;

  int n = nums.size();

  for(int i=0;i<n;i++){
      int x = nums[i] - i;
      diff[i] = x;
  }

  for(auto i: diff){
      count[i.second]++;
  }

  for(auto i: diff){
      int l = (n - 1) - i.first;
      int c = count[i.second] - 1;

      ans += l - c; 
      --count[i.second];
  }

  return ans;
}

//Optimised Solution Using Single Iteration by checking diff in map

long long countBadPairs(vector<int>& nums) {
  int n=nums.size();
  long long ans=0;
  unordered_map<int,int> mp;
  for(int i=0;i<n;i++){
      int diff=nums[i]-i;
      if(mp.find(diff)!=mp.end()){
          ans+=(i-mp[diff]);
      }
      else{
          ans+=i;
      }
      mp[diff]++;
  }
  return ans;
}

int main()
{
    vector<int> nums = {4,1,3,3,8};
    cout<<countBadPairs(nums)<<endl;
    return 0;
}