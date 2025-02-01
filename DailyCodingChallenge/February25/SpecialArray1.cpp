#include<bits/stdc++.h>
using namespace std;

bool isArraySpecial(vector<int>& nums) {
    int n = nums.size();
    if(n==1){return true;}

    for(int i=0;i<n-1;i++){
        if(nums[i]%2 == 0){
            if(nums[i+1]%2 == 0){
                return false;
            }
        }else{
            if(nums[i+1]%2 != 0){
                return false;
            }
        }
    }

    return true;
}

int main()
{
  vector<int> nums = {2, 1, 6, 5};
  if(isArraySpecial(nums)){
      cout << "The array is special." << endl;
  } else {
      cout << "The array is not special." << endl;
  }

  return 0;
}