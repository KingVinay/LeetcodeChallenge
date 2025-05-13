#include<bits/stdc++.h>
using namespace std;

int lengthAfterTransformations(string s, int t) {
        int kmod = 1e9  + 7;
        int c[26] = {0}, ans = s.size();
        for (int i = 0; i < s.size(); i++) {
            c[s[i] - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            int tmp = c[0], tmp2;
            for (int j = 1; j < 26; j++) {
                tmp2 = c[j];
                c[j] = tmp;
                tmp = tmp2;
            }
            c[0] = tmp;
            c[1] += (tmp % kmod);
            c[1] %= kmod;
            ans += tmp;
            ans %= kmod;
        }
        return ans;
    }

int main()
{
    string s = "abc";
    int t = 2;
    int result = lengthAfterTransformations(s, t);
    
    cout << "Resulting length: " << result << endl;
    
    return 0;
}