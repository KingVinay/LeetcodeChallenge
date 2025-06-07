#include<bits/stdc++.h>
using namespace std;

string clearStars(string s) {
        stack<int> charStack[26]; 
        int n = s.length();              
        vector<bool> toRemove(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {  
                toRemove[i] = true;

                for (int j = 0; j < 26; ++j) {
                    if (!charStack[j].empty()) {
                        toRemove[charStack[j].top()] = true;
                        charStack[j].pop();
                        break;
                    }
                }
            } else {
                charStack[s[i] - 'a'].push(i);
            }
        }

        string result;
        for (int i = 0; i < n; ++i) {
            if (!toRemove[i]) {
                result.push_back(s[i]);
            }
        }
        return result;
    }

int main()
{
    string s;
    cin >> s;

    string result = clearStars(s);
    cout << result << endl;

    return 0;
}