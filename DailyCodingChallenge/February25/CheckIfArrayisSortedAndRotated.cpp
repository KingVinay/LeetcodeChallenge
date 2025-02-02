#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            count++;
        }

        if(count>1){return false;}
    }

    if(nums[n-1] > nums[0]){count++;}
    return (count <= 1);
}

int main()
{
  vector<int> nums = {3, 4, 5, 1, 2};
  if(check(nums)){
      cout << "The array is sorted and rotated." << endl;
  } else {
      cout << "The array is not sorted and rotated." << endl;
  }

  return 0;
}