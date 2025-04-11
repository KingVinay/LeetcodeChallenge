#include<bits/stdc++.h>
using namespace std;

int countSymmetricIntegers(int low, int high) {
  int ans = 0;
  for(int i=low;i<=high;i++){
      string s = to_string(i);
      int len = s.length();

      if(len%2 != 0){continue;}

      int first = 0,second = 0;

      for(int j=0;j<len/2;j++){
          first += s[j] - '0';
          second += s[len-j-1] - '0';
      }

      if(first == second){
          ans++;
      }
  }

  return ans;
}

int main()
{
  int low = 1;
  int high = 1000;

  int result = countSymmetricIntegers(low, high);
  cout << "Count of symmetric integers: " << result << endl;

  return 0;
}