#include<bits/stdc++.h>
using namespace std;

int minimizeMax(vector<int>& nums, int p) {
        ranges::sort(nums);

        int l = 0;
        int r = nums.back() - nums.front();

        while (l < r) {
            const int m = (l + r) / 2;
            if (numPairs(nums, m) >= p)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    int numPairs(const vector<int>& nums, int maxDiff) {
        int pairs = 0;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] - nums[i - 1] <= maxDiff) {
                ++pairs;
                ++i;
            }
        return pairs;
    }

int main()
{
    vector<int> nums;
    int n, x, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    int result = minimizeMax(nums, p);
    cout << result << endl;

    return 0;
}