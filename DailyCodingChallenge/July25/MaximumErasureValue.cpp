#include<bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    int ans = 0;
    int score = 0;
    unordered_set<int> seen;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
        while (!seen.insert(nums[r]).second) {
            score -= nums[l];
            seen.erase(nums[l++]);
        }
        score += nums[r];
        ans = max(ans, score);
    }

    return ans;
}

int main()
{
    vector<int> nums;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cout << maximumUniqueSubarray(nums) << endl;
    return 0;
}