#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        return s == string(s.rbegin(), s.rend());
    }

    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += to_string(num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int len = 1;
        while (n > 0) {
            for (int half = pow(10, (len - 1) / 2); half < pow(10, (len + 1) / 2) && n > 0; ++half) {
                string h = to_string(half);
                string r = h;
                reverse(r.begin(), r.end());
                string full = h + (len % 2 ? r.substr(1) : r);
                long long num = stoll(full);
                if (isPalindrome(toBaseK(num, k))) {
                    sum += num;
                    --n;
                }
            }
            ++len;
        }
        return sum;
    }

int main()
{
    int k = 3; // Base
    int n = 5; // Number of k-mirror numbers to sum

    long long result = kMirror(k, n);
    cout << "The sum of the first " << n << " k-mirror numbers in base " << k << " is: " << result << endl;

    return 0;
}