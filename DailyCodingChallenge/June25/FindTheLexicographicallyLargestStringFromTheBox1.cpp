#include<bits/stdc++.h>
using namespace std;

string answerString(string word, int numFriends) {
        int n = word.size();
        int limit = numFriends-1;
        int len = n-(numFriends-1);
        string ans = "";
        if(numFriends==1)
            return word;
        for(int i=0; i<n; i++)
            ans = max(ans, word.substr(i, min(len, n-i)));
        
        return ans;
    }

int main()
{
    string word;
    int numFriends;
    cin >> word >> numFriends;

    string result = answerString(word, numFriends);
    cout << result << endl;

    return 0;
}