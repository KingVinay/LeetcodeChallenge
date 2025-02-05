#include<bits/stdc++.h>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    if(s1==s2){return true;}

    vector<int> a(26,0);
    int check = 0;
    for(int i=0;i<s1.length();i++){
        a[s1[i] - 'a'] += 1;
        if(s1[i]!=s2[i]){
            check++;
        }
    }

    for(int i=0;i<s2.length();i++){
        a[s2[i] - 'a'] -= 1;
        if(a[s2[i] - 'a'] < 0){
            return false;
        }
    }
    
    if(check==2){
        return true;
    }

    return false;
}

int main()
{
  string s1 = "abcd", s2 = "bcdf";
  cout << areAlmostEqual(s1, s2) << endl;
  return 0;
}