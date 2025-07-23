#include<bits/stdc++.h>
using namespace std;

int maximumGain(string s, int x, int y) {
        return x > y ? gain(s, "ab", x, "ba", y) : gain(s, "ba", y, "ab", x);
    }

    int gain(string s, string sub1, int point1, string sub2, int point2) {
        int points = 0;
        vector<char> stack1;
        vector<char> stack2;

        for (char c : s)
            if (!stack1.empty() && stack1.back() == sub1[0] && c == sub1[1]) {
                stack1.pop_back();
                points += point1;
            } else {
                stack1.push_back(c);
            }

        for (char c : stack1)
            if (!stack2.empty() && stack2.back() == sub2[0] && c == sub2[1]) {
                stack2.pop_back();
                points += point2;
            } else {
                stack2.push_back(c);
            }

        return points;
    }

int main()
{
    string s;
    int x, y;
    cin >> s >> x >> y;
    cout << maximumGain(s, x, y) << endl;
    return 0;
}