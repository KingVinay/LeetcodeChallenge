#include<bits/stdc++.h>
using namespace std;

int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> s;
        int l = 0;

        for (int a : arr) {
            int r = s.size();
            s.push_back(a);
            for (int i = l; i < r; ++i)
                if (s.back() != (s[i] | a))
                    s.push_back(s[i] | a);
            l = r;
        }

        return unordered_set<int>(s.begin(), s.end()).size();
    }

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1};
    int result = subarrayBitwiseORs(arr);
    
    cout << "Number of Unique Bitwise ORs of Subarrays: " << result << endl;
    
    return 0;
}