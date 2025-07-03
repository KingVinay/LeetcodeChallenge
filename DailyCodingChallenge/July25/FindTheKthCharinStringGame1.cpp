#include<bits/stdc++.h>
using namespace std;

int count_ones(int n) {
    int result = 0;
    while (n) {
        n &= n - 1;
        ++result;
    }
    return result;
}

char kthCharacter(int k) {
    return 'a' + count_ones(k - 1);
}

int main()
{
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    if (k <= 0) {
        cout << "Invalid input. k must be a positive integer." << endl;
        return 1;
    }

    char result = kthCharacter(k);
    cout << "The " << k << "th character in the string game is: " << result << endl;

    return 0;
}