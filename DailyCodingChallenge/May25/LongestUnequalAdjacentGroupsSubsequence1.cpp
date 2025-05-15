#include<bits/stdc++.h>
using namespace std;

vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans;
        int groupId = -1;

        for (int i = 0; i < groups.size(); ++i)
            if (groups[i] != groupId) {
                groupId = groups[i];
                ans.push_back(words[i]);
            }

        return ans;
    }

int main()
{
    vector<string> words = {"a", "b", "c", "d", "e", "f"};
    vector<int> groups = {1, 0, 0, 1, 1, 0};

    vector<string> result = getLongestSubsequence(words, groups);

    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}