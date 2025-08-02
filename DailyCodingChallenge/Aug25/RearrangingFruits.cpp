#include<bits/stdc++.h>
using namespace std;

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    vector<int> swapped;
    unordered_map<int, int> count;

    for (int b : basket1)
        ++count[b];

    for (int b : basket2)
        --count[b];

    for (auto& [num, freq] : count) {
        if (freq % 2 != 0)
            return -1;
        for (int i = 0; i < abs(freq) / 2; ++i)
            swapped.push_back(num);
    }

    int minNum = min(ranges::min(basket1), ranges::min(basket2));
    auto midIt = swapped.begin() + swapped.size() / 2;
    nth_element(swapped.begin(), midIt, swapped.end());
    return accumulate(
        swapped.begin(), midIt, 0L,
        [minNum](long acc, int num) { return acc + min(2 * minNum, num); });
}

int main()
{
    vector<int> basket1 = {1, 2, 3, 4};
    vector<int> basket2 = {2, 3, 4, 5};

    long long result = minCost(basket1, basket2);
    
    if (result != -1)
        cout << "Minimum cost to make baskets equal: " << result << endl;
    else
        cout << "It's not possible to make the baskets equal." << endl;

    return 0;
}