#include<bits/stdc++.h>
using namespace std;

// Using Binary Search on Ans

bool check(vector<int>& a, int mid, long long k) {
  long long count = 0;
  for (int i = 0; i < a.size(); i++) {
      count += a[i] / mid;
  }
  return count >= k;
}

int maximumCandies(vector<int>& candies, long long k) {
  long long end = 0, start = 1;
  for(auto x: candies) end += x;
  end /= k;
  while(start <= end) {
      long long mid = start + (end - start) / 2;
      if(check(candies, mid, k)) start = mid + 1;
      else end = mid - 1;
  }
  return end;
}

int main()
{
    vector<int> candies = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long k = 5;
    cout<<maximumCandies(candies, k)<<endl;
    return 0;
}