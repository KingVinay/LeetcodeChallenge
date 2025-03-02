#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
  vector<vector<int>> ans;
  int i=0,j=0;
  while(i<nums1.size() && j<nums2.size()){
      if(nums1[i][0] == nums2[j][0]){
          nums1[i][1] += nums2[j++][1];
          ans.push_back(nums1[i++]);
      }else if(nums1[i][0] < nums2[j][0]){
          ans.push_back(nums1[i++]);
      }else{
          ans.push_back(nums2[j++]);
      }
  }

  while(i<nums1.size()){
      ans.push_back(nums1[i++]);
  }
  while(j<nums2.size()){
      ans.push_back(nums2[j++]);
  }

  return ans;
}

int main()
{
  vector<vector<int>> nums1 = {{1,2},{3,4},{5,6}};
  vector<vector<int>> nums2 = {{2,5},{2,6},{3,7},{8,9}};
  vector<vector<int>> ans = mergeArrays(nums1,nums2);
  for(auto v: ans){
    cout << v[0] << " " << v[1] << endl;
  }
  return 0;
}