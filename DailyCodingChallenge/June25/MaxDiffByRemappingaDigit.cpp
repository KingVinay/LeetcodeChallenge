#include<bits/stdc++.h>
using namespace std;

int minMaxDifference(int num) {
        string s = to_string(num);
        char c, d = s[0];
        for(int i=0;i<s.length();i++){
            if(s[i] != '9'){
                c = s[i];
                break;
            }
        }
        string mn = s, mx = s;
        for(int i=0;i<s.length();i++){
            if(d == mn[i]){
                mn[i] = '0';
            }
            if(c == mx[i]){
                mx[i] = '9';
            }
        }

        return stoi(mx) - stoi(mn);
    }

int main()
{
    int num;
    cin >> num;

    int result = minMaxDifference(num);
    cout << result << endl;

    return 0;
}