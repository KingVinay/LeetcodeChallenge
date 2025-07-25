#include<bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mn = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > mn)
                ans = max(ans, nums[i] - mn);
            mn = min(mn, nums[i]);
        }

        return ans;
    }

int main()
{
    vector<int> nums;
    int n, x;
    cin >> n; // Read the size of the array
    for (int i = 0; i < n; ++i) {
        cin >> x; // Read each element
        nums.push_back(x);
    }

    int result = maximumDifference(nums);
    cout << result << endl;

    return 0;
}