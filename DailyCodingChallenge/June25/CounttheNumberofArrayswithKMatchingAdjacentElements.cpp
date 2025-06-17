#include<bits/stdc++.h>
using namespace std;

int countGoodArrays(int n, int m, int k) {
        auto [fact, invFact] = getFactAndInvFact(n);
        return m * modPow(m - 1, n - k - 1) % kMod *
               nCk(n - 1, k, fact, invFact) % kMod;
    }

    int kMod = 1e9 + 7;

    long modPow(long x, long n) {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return x * modPow(x % kMod, (n - 1)) % kMod;
        return modPow(x * x % kMod, (n / 2)) % kMod;
    }

    pair<vector<long>, vector<long>> getFactAndInvFact(int n) {
        vector<long> fact(n + 1);
        vector<long> invFact(n + 1);
        vector<long> inv(n + 1);
        fact[0] = invFact[0] = 1;
        inv[0] = inv[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i >= 2)
                inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
            fact[i] = fact[i - 1] * i % kMod;
            invFact[i] = invFact[i - 1] * inv[i] % kMod;
        }
        return {fact, invFact};
    }

    int nCk(int n, int k, vector<long>& fact,
            vector<long>& invFact) {
        return fact[n] * invFact[k] % kMod * invFact[n - k] % kMod;
    }

int main()
{
    int n, m, k;
    cin >> n >> m >> k; 
    int result = countGoodArrays(n, m, k);
    cout << result << endl;

    return 0;
}