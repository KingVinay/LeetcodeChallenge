#include<bits/stdc++.h>
using namespace std;

int digit[100];

long long kMirror(int k, int n) {
    auto isPalindrome = [&](long long x) -> bool {
        int length = -1;
        while (x) {
            ++length;
            digit[length] = x % k;
            x /= k;
        }
        for (int i = 0, j = length; i < j; ++i, --j) {
            if (digit[i] != digit[j]) {
                return false;
            }
        }
        return true;
    };

    int left = 1, count = 0;
    long long ans = 0;
    while (count < n) {
        int right = left * 10;
        for (int op = 0; op < 2; ++op) {
            for (int i = left; i < right && count < n; ++i) {
                long long combined = i;
                int x = (op == 0 ? i / 10 : i);
                while (x) {
                    combined = combined * 10 + x % 10;
                    x /= 10;
                }
                if (isPalindrome(combined)) {
                    ++count;
                    ans += combined;
                }
            }
        }
        left = right;
    }
    return ans;
}

int main()
{
    int k = 3; // Base
    int n = 5; // Number of k-mirror numbers to sum

    long long result = kMirror(k, n);
    cout << "The sum of the first " << n << " k-mirror numbers in base " << k << " is: " << result << endl;

    return 0;
}