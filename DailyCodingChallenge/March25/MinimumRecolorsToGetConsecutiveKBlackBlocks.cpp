#include<bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k) {
  int cw = 0;
  for(int i=0;i<k;i++){
      if(blocks[i] == 'W'){
          cw++;
      }
  }

  int j = 0,ans = cw;
  for(int i=k;i<blocks.length();i++){
      if(blocks[j] == 'W' && blocks[i] == 'B'){
          cw--;
      }else if(blocks[j] == 'B' && blocks[i] == 'W'){
          cw++;
      }

      ans = min(cw,ans);
      j++;
  }

  return ans;
}

int main()
{
  string blocks = "BBWBWBWBBWB";
  int k = 6;
  cout<<minimumRecolors(blocks,k)<<endl;
  return 0;
}