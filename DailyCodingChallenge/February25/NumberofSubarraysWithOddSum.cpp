#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
int numOfSubarrays(vector<int>& arr) {
  int n = arr.size();
  int ans = 0, cs = 0;
  // count of odd and even cumulative arrays
  int odd = 0, even = 1; // even is 1 because cs = 0 is even

  for(int i=0;i<n;i++){
      cs += arr[i];
      if(cs%2==1){
        // every odd element with even sum gives odd sum
        ans += even;
        odd += 1;
      }else{
          // every even element with odd sum gives odd sum
          ans += odd;
          even++;
      }

      ans%= mod;
  }

  return ans;
}