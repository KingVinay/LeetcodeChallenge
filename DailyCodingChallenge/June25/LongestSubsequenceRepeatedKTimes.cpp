#include<bits/stdc++.h>
using namespace std;

string longestSubsequenceRepeatedK(string s, int k) {
        string ans;
        vector<int> count(26);
        vector<char> possibleChars;
        queue<string> q{{""}};

        for (char c : s)
            ++count[c - 'a'];

        for (char c = 'a'; c <= 'z'; ++c)
            if (count[c - 'a'] >= k)
                possibleChars.push_back(c);

        while (!q.empty()) {
            string currSubseq = q.front();
            q.pop();
            if (currSubseq.length() * k > s.length())
                return ans;
            for (char c : possibleChars) {
                string newSubseq = currSubseq + c;
                if (isSubsequence(newSubseq, s, k)) {
                    q.push(newSubseq);
                    ans = newSubseq;
                }
            }
        }

        return ans;
    }
    bool isSubsequence(string subseq, string s, int k) {
        int i = 0;
        for (char c : s)
            if (c == subseq[i])
                if (++i == subseq.length()) {
                    if (--k == 0)
                        return true;
                    i = 0;
                }
        return false;
    }

int main()
{
    string s = "abcabcabc";
    int k = 3;
    cout << longestSubsequenceRepeatedK(s, k) << endl; // Output: "abc"
    return 0;
}