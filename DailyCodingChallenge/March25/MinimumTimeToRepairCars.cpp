#include<bits/stdc++.h>
using namespace std;

long fixedcars(vector<int>& ranks, long min){
  long cnt = 0;
  for(int r: ranks){
      cnt += sqrt(min/r);
  }
  return cnt;
}

long long repairCars(vector<int>& ranks, int cars) {
  long l = 0;
  long r = (long)(*min_element(ranks.begin(),ranks.end())) * cars * cars;

  long ans;
  while(l<=r){
      long mid = (l + r)/2;
      if(fixedcars(ranks,mid) >= cars){
          ans = mid;
          r = mid - 1;
      }else{
          l = mid + 1;
      } 
  }

  return ans;
}

int main()
{
  vector<int> ranks = {3, 5, 7, 9, 10};
  int cars = 3;
  cout<<repairCars(ranks, cars)<<endl;
  return 0;
}