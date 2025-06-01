#include<bits/stdc++.h>
using namespace std;
long long distributeCandies(int n, int limit) {
        auto comb2 = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }
int main()
{
    int n, limit;
    cout << "Enter the number of candies (n): ";
    cin >> n;
    cout << "Enter the limit for candies per child: ";
    cin >> limit;

    long long result = distributeCandies(n, limit);
    cout << "Number of ways to distribute candies: " << result << endl;

    return 0;
}