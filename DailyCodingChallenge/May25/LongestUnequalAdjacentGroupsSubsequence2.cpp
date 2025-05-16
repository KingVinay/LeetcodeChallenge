#include<bits/stdc++.h>
using namespace std;

vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        vector<string> ans;
        int n = groups.size();
    
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                if (groups[i] == groups[j])
                    continue;
                if (words[i].length() != words[j].length())
                    continue;
                if (hammingDist(words[i], words[j]) != 1)
                    continue;
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

        int index = ranges::max_element(dp) - dp.begin();
        while (index != -1) {
            ans.push_back(words[index]);
            index = prev[index];
        }

        ranges::reverse(ans);
        return ans;
    }

    int hammingDist(string& s1, string& s2) {
        int dist = 0;
        for (int i = 0; i < s1.length(); ++i)
            if (s1[i] != s2[i])
                ++dist;
        return dist;
    }

int main()
{
    vector<string> words = {"a", "b", "c", "d", "e", "f"};
    vector<int> groups = {1, 0, 0, 1, 1, 0};

    vector<string> result = getWordsInLongestSubsequence(words, groups);

    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}