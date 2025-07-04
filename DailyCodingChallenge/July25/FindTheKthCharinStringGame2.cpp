#include<bits/stdc++.h>
using namespace std;

char kthCharacter(long long k, vector<int>& operations) {
        int operationsCount = ceil(log2(k));
        int increases = 0;

        for (int i = operationsCount - 1; i >= 0; --i) {
            const long halfSize = 1L << i;
            if (k > halfSize) {
                k -= halfSize;
                increases += operations[i];
            }
        }

        return 'a' + increases % 26;
    }

int main()
{
    long long k;
    cout << "Enter the value of k: ";
    cin >> k;

    if (k <= 0) {
        cout << "Invalid input. k must be a positive integer." << endl;
        return 1;
    }

    vector<int> operations = {0, 1, 2, 3, 4, 5, 6, 7}; // Example operations
    char result = kthCharacter(k, operations);
    cout << "The " << k << "th character in the string game is: " << result << endl;

    return 0;
}