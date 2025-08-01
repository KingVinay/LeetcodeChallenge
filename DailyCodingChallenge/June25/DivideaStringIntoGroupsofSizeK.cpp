#include<bits/stdc++.h>
using namespace std;

vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for (int i = 0; i < s.length(); i += k)
            ans.push_back(i + k > s.length()
                              ? s.substr(i) + string(i + k - s.length(), fill)
                              : s.substr(i, k));

        return ans;
    }

int main()
{
    string s = "abcdef";
    int k = 3;
    char fill = 'x';

    vector<string> result = divideString(s, k, fill);
    for (const string& str : result)
        cout << str << endl;

    return 0;
}