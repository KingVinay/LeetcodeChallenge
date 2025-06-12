#include<bits/stdc++.h>
using namespace std;

int maxAdjacentDistance(vector<int>& nums) {
        int res = 0,n = nums.size();
        for(int i=0;i<n-1;i++){
            int diff = abs(nums[i]-nums[i+1]);
            res = max(diff,res);
        }
        res = max(res, abs(nums[0]-nums[n-1]));
        return res;
    }

int main()
{
    vector<int> nums;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    int result = maxAdjacentDistance(nums);
    cout << result << endl;

    return 0;
}