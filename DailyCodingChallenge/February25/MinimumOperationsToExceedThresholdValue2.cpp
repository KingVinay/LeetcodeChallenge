#include<bits/stdc++.h>
using namespace std;

// Using Min Heap (Priority Queue) in Time - O(nlogn)
// long type casting is used to avoid overflow

int minOperations(vector<int>& nums, int k) {
  priority_queue<long, vector<long>, greater<long> > pq;
  for(int i=0;i<nums.size();i++){
      pq.push((long)nums[i]);
  }

  int ans = 0;

  while(pq.size() > 1){
      long x = pq.top();
      pq.pop();
      if(x>=k){
          return ans;
      }
      long y = pq.top();
      pq.pop();

      long temp = 2 * min(x,y) + max(x,y);
      pq.push(temp);

      ans++;
  }

  return ans;
}

int main()
{
  vector<int> nums = {2,11,10,1,3};
  int k = 5;
  cout << minOperations(nums, k) << endl;
  return 0;
}