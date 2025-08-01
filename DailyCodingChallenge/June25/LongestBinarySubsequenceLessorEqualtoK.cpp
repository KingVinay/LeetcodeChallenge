#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(string s, int k) {
        int oneCount = 0;
        int num = 0;
        int pow = 1;

        for (int i = s.length() - 1; i >= 0 && num + pow <= k; --i) {
            if (s[i] == '1') {
                ++oneCount;
                num += pow;
            }
            pow *= 2;
        }

        return ranges::count(s, '0') + oneCount;
    }

int main()
{
    string s = "001101";
    int k = 5;
    cout << longestSubsequence(s, k) << endl; // Output: 4
    return 0;
}