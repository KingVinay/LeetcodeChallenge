#include<bits/stdc++.h>
using namespace std;

string makeFancyString(string s) {
    string ans;
    for (char c : s)
        if (ans.length() < 2 || ans.back() != c || ans[ans.size() - 2] != c)
            ans.push_back(c);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << makeFancyString(s) << endl;
    return 0;
}