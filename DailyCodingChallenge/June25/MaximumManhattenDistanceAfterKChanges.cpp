#include<bits/stdc++.h>
using namespace std;

int maxDistance(string s, int k) {
        return max({flip(s, k, "NE"), flip(s, k, "NW"),
                flip(s, k, "SE"), flip(s, k, "SW")});
    }

    int flip(string& s, int k, string direction) {
        int res = 0;
        int pos = 0;
        int opposite = 0;

        for (char c : s) {
        if (direction.find(c) != string::npos) {
            ++pos;
        } else {
            --pos;
            ++opposite;
        }
        res = max(res, pos + 2 * min(k, opposite));
        }

        return res;
    }

int main()
{
  string s;
  int k;
  cin >> s >> k;

  int result = maxDistance(s, k);
  
  cout << result << endl;

  return 0;
}