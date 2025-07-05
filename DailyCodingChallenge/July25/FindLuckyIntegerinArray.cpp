#include<bits/stdc++.h>
using namespace std;

int findLucky(vector<int>& arr) {
  unordered_map<int,int> mp;
  for(int i=0;i<arr.size();i++){
      mp[arr[i]]++;
  }
  int ans = -1;

  for(auto i: mp){
      if(i.first == i.second){
          ans= max(i.first, ans);
      }
  }

  return ans;
}

int main()
{
    vector<int> arr = {2, 2, 3, 4};
    int luckyInteger = findLucky(arr);
    
    if (luckyInteger != -1) {
        cout << "The lucky integer is: " << luckyInteger << endl;
    } else {
        cout << "There is no lucky integer in the array." << endl;
    }

    return 0;
}