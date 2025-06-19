#include<bits/stdc++.h>
using namespace std;

int partitionArray(vector<int>& nums, int k) {
        ranges::sort(nums);

        int ans = 1;
        int mn = nums[0];

        for (int i = 1; i < nums.size(); ++i)
            if (mn + k < nums[i]) {
                ++ans;
                mn = nums[i];
            }

        return ans;
    }

int main()
{
    vector<int> nums;
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }

    int result = partitionArray(nums, k);
    
    cout << result << endl;

    return 0;
}