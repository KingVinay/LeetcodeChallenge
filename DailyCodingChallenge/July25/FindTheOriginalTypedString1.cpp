#include<bits/stdc++.h>
using namespace std;

int possibleStringCount(string word) {
        int ans = 1;
        for (int i = 1; i < word.length(); ++i)
            if (word[i] == word[i - 1])
                ++ans;
        return ans;
    }

int main()
{
    string word = "aabbcc";
    int result = possibleStringCount(word);
    
    cout << "Number of possible original typed strings: " << result << endl;

    return 0;
}