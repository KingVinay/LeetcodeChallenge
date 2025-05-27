#include<bits/stdc++.h>
using namespace std;

int differenceOfSums(int n, int m) {
        int ds = 0, nds = 0;
        for(int i=1;i<=n;i++){
            if(i%m == 0) ds+= i;
            else nds += i;
        }

        return nds - ds;
    }

int main()
{
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    int result = differenceOfSums(n, m);
    cout << "Difference of non-divisible and divisible sums: " << result << endl;

    return 0;
}