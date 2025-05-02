#include<bits/stdc++.h>
using namespace std;

string pushDominoes(string dominoes) {
  int L = -1;
  int R = -1;

  for (int i = 0; i <= dominoes.length(); ++i)
      if (i == dominoes.length() || dominoes[i] == 'R') {
          if (L < R)
              while (R < i)
                  dominoes[R++] = 'R';
          R = i;
      } else if (dominoes[i] == 'L') {
          if (R < L || L == -1 && R == -1) {
              if (L == -1 && R == -1)
                  ++L;
              while (L < i)
                  dominoes[L++] = 'L';
          } else {
              int l = R + 1;
              int r = i - 1;
              while (l < r) {
                  dominoes[l++] = 'R';
                  dominoes[r--] = 'L';
              }
          }
          L = i;
      }

  return dominoes;
}

int main()
{
  string dominoes = ".L.R...LR..L..";
  string result = pushDominoes(dominoes);
  cout << "The final state of the dominoes is: " << result << endl;

  return 0;
}