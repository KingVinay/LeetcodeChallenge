#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int> l(n, 1);
        vector<int> r(n, 1);

        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i - 1])
                l[i] = l[i - 1] + 1;

        for (int i = n - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1])
                r[i] = r[i + 1] + 1;

        for (int i = 0; i < n; ++i)
            ans += max(l[i], r[i]);

        return ans;
    }

int main()
{
    vector<int> ratings;
    int n, rating;

    cout << "Enter the number of children: ";
    cin >> n;
    cout << "Enter the ratings of the children: ";
    
    for (int i = 0; i < n; ++i) {
        cin >> rating;
        ratings.push_back(rating);
    }

    int result = candy(ratings);
    cout << "Minimum number of candies required: " << result << endl;

    return 0;
}