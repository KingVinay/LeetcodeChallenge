#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string>& words) {
        int ans = 0;
        vector<vector<int>> count(26, vector<int>(26));

        for (string& word : words) {
            int i = word[0] - 'a';
            int j = word[1] - 'a';
            if (count[j][i]) {
                ans += 4;
                --count[j][i];
            } else {
                ++count[i][j];
            }
        }

        for (int i = 0; i < 26; ++i)
            if (count[i][i])
                return ans + 2;

        return ans;
    }

int main(){
    vector<string> words = {"ab", "ba", "cd", "dc", "ef", "fe", "gh", "hg"};
    int result = longestPalindrome(words);
    cout << "Length of the longest palindrome that can be formed: " << result << endl;

    return 0;
}