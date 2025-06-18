#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        ranges::sort(nums);

        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i - 2] > k)
                return {};
            ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
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

    vector<vector<int>> result = divideArray(nums, k);
    
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        cout << "[";
        for (const auto& vec : result) {
            cout << "[";
            for (int i = 0; i < vec.size(); ++i) {
                cout << vec[i];
                if (i < vec.size() - 1) cout << ", ";
            }
            cout << "]";
        }
        cout << "]" << endl;
    }

    return 0;
}