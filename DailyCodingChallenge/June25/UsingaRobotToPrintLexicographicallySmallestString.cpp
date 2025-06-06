#include<bits/stdc++.h>
using namespace std;

 string robotWithString(string s) {
        string ans;
        vector<int> count(26);
        stack<char> stack;

        for (char c : s)
            ++count[c - 'a'];

        for (char c : s) {
            stack.push(c);
            --count[c - 'a'];
            char minChar = getMinChar(count);
            while (!stack.empty() && stack.top() <= minChar)
                ans += stack.top(), stack.pop();
        }

        while (!stack.empty())
            ans += stack.top(), stack.pop();

        return ans;
    }

    char getMinChar(vector<int>& count) {
        for (int i = 0; i < 26; ++i)
            if (count[i])
                return 'a' + i;
        return 'a';
    }

int main()
{
    string s;
    cin >> s;

    string result = robotWithString(s);
    cout << result << endl;

    return 0;
}