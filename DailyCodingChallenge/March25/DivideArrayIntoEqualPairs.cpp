#include<bits/stdc++.h>
using namespace std;

bool divideArray(vector<int>& nums) {
  unordered_map<int,int> store;
  for(int i=0;i<nums.size();i++){
      store[nums[i]]++;
  }

  int check = 0;

  for(auto m: store){
      if(m.second % 2 !=0){
          return false;
      }else{
          check += m.second/2;
      }
  }

  return check == (nums.size()/2);
}

int main()
{
  vector<int> nums = {1, 2, 2, 1, 3, 4, 4, 3};
  cout<<divideArray(nums)<<endl;
  return 0;
}