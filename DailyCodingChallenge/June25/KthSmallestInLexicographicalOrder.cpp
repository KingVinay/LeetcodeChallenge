#include<bits/stdc++.h>
using namespace std;

int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1;

        while (k > 0) {
            long steps = 0, first = curr, last = curr;

            while (first <= n) {
                steps += min(n + 1L, last + 1L) - first;
                first *= 10;
                last = last * 10 + 9;
            }

            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return (int)curr;
    }

int main()
{
    int n, k;
    cin >> n >> k;

    int result = findKthNumber(n, k);
    cout << result << endl;

    return 0;
}