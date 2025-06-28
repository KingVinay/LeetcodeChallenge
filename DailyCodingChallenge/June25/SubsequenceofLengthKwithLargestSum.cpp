#include<bits/stdc++.h>
using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(i, nums[i]);
        }

        sort(vals.begin(), vals.end(),
             [&](auto x1, auto x2) { return x1.second > x2.second; });
    
        sort(vals.begin(), vals.begin() + k);
        
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(vals[i].second);
        }
        return res;
    }

int main()
{
    vector<int> nums = {3, 4, 3, 2, 4, 6, 7, 5};
    int k = 4;
    vector<int> result = maxSubsequence(nums, k);
    
    cout << "Subsequence of length " << k << " with largest sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}