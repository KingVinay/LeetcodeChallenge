#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(2*n + c)
vector<int> pivotArray(vector<int>& nums, int pivot) {
  int n = nums.size();
  vector<int> res(n,0);

  int c = 0;
  int pt = 0;
  
  for (int i = 0; i < n; i++) {
      if (nums[i] < pivot) {
          res[pt++] = nums[i];
      } else if (nums[i] == pivot) {
          c++;
      }
  }

  while (c--) {
      res[pt++] = pivot;
  }

  for (int i = 0; i < n; i++) {
      if (nums[i] > pivot) {
          res[pt++] = nums[i];
      }
  }

  return res;
}

// Time complexity: O(3*n)
vector<int> pivotArray(vector<int>& nums, int pivot) {
  vector<int> ans;
  for(int i=0;i<nums.size();i++){
      if(nums[i] < pivot){
          ans.push_back(nums[i]);
      }
  }

  for(int i=0;i<nums.size();i++){
      if(nums[i] == pivot){
          ans.push_back(nums[i]);
      }
  }

  for(int i=0;i<nums.size();i++){
      if(nums[i] > pivot){
          ans.push_back(nums[i]);
      }
  }

  return ans;
}

int main()
{
  vector<int> nums = {9,7,8,3,2,1,5,4,6};
  int pivot = 5;
  vector<int> ans = pivotArray(nums,pivot);
  for(auto v: ans){
    cout << v << " ";
  }
  return 0;
}