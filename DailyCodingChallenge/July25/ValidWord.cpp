#include<bits/stdc++.h>
using namespace std;

bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant = false;
      
        bool vowelStatus[26] = {false};
        std::string vowels = "aeiou";
      
        for (char c : vowels) {
            vowelStatus[c - 'a'] = true;
        }
      
        for (char c : word) {
            if (std::isalpha(c)) { 
                if (vowelStatus[std::tolower(c) - 'a']) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!std::isdigit(c)) { 
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }

int main()
{
    string word1 = "hello123";
    string word2 = "aeiou";
    string word3 = "12345";
    string word4 = "abc";

    cout << "Is '" << word1 << "' a valid word? " << (isValid(word1) ? "Yes" : "No") << endl;
    cout << "Is '" << word2 << "' a valid word? " << (isValid(word2) ? "Yes" : "No") << endl;
    cout << "Is '" << word3 << "' a valid word? " << (isValid(word3) ? "Yes" : "No") << endl;
    cout << "Is '" << word4 << "' a valid word? " << (isValid(word4) ? "Yes" : "No") << endl;

    return 0;
}