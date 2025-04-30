#include<bits/stdc++.h>
using namespace std;

// By Converting to String in O(n)

int findNumbers(vector<int>& nums) {
  int ans = 0;
  for(int i=0;i<nums.size();i++){
      string s = to_string(nums[i]);
      if(s.length()%2 == 0){
          ans++;
      }
  }
  return ans;
}

// By Counting Digits in O(nlog(n))

int findNumbers(vector<int>& nums) {
  int ans = 0;
  for(int i=0;i<nums.size();i++){
      int count = 0,temp = nums[i];
      while(temp){
          temp /=10;
          count++;
      }

      if(count%2 == 0){
          ans++;
      }
  }

  return ans;
}

int main()
{
  vector<int> nums = {12, 345, 2, 6, 7896};
  int result = findNumbers(nums);
  cout << "The count of numbers with even digits is: " << result << endl;
  return 0;
}