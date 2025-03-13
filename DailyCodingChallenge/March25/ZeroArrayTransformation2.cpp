#include<bits/stdc++.h>
using namespace std;

// Using Binary Search on And and Difference Array Time - O(n * logn)

bool check(vector<int>& nums, vector<vector<int>>& queries, vector<int> d, int k) {
  for (int i = 0; i < k; ++i) {
      int start = queries[i][0];
      int end = queries[i][1];
      int value = queries[i][2];

      d[start] += value;
      d[end + 1] -= value;
  }

  for (int i = 0, sum = 0; i < nums.size(); ++i) {
      sum += d[i];
      if (nums[i] > sum) {
          return false;
      }
  }
  return true;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
  int n = nums.size();
  vector<int> d(n + 1, 0);
  int m = queries.size();
  int left = 0, right = m + 1;

  while (left < right) {
      int mid = (left + right) / 2;
      if (check(nums, queries, d, mid)) {
          right = mid;
      } else {
          left = mid + 1;
      }
  }
  return left > m ? -1 : left;
}

// Time - O(n^2) Using Nested Loops
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
  int ans = -1;
  vector<int> check(nums.size(),0);
  for(int i=0;i<queries.size();i++){
      int st = queries[i][0];
      int end = queries[i][1];
      int val = queries[i][2];

      for(int j=st;j<=end;j++){
          if(nums[j]==0){
              continue;
          }else if(nums[j] >= val){
              nums[j]-=val;
          }else{
              nums[j] -= nums[j];
          }
      }

      if(check == nums){
          ans = i+1;
          break;
      }
  }

  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<vector<int>> queries = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}};
  cout<<minZeroArray(nums, queries)<<endl;
  return 0;
}