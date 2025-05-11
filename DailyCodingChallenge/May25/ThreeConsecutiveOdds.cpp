#include<bits/stdc++.h>
using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==1){
                cnt++;
            }else{
                cnt = 0;
            }

            if(cnt == 3){
                return true;
            }
        }
        return false;
    }

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 7, 9};
    cout << threeConsecutiveOdds(arr) << endl; // Output: true
    return 0;
}