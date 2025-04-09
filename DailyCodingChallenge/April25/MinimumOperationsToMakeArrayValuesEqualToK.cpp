#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int k) {
  unordered_set<int> st;
  for(int i=0;i<nums.size();i++){
      if(nums[i] > k){
          st.insert(nums[i]);
      }else if(nums[i] < k){
          return -1;
      }
  }
  return st.size();
}

int main()
{
  vector<int> nums = {5,2,5,4,5};
  int k = 2;
  int result = minOperations(nums, k);
  cout << "Minimum number of operations to make elements equal to " << k << ": " << result << endl;

  return 0;
}