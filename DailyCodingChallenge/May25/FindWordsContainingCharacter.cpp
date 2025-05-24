#include<bits/stdc++.h>
using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            if(words[i].find(x) != string::npos){
                ans.push_back(i);
            }
        }
        return ans;
    }

int main()
{
    vector<string> words = {"hello", "world", "example", "test"};
    char x = 'l';

    vector<int> result = findWordsContaining(words, x);
    cout << "Indices of words containing '" << x << "': ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}