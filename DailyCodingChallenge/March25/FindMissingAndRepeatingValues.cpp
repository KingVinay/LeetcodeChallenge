#include<bits/stdc++.h>
using namespace std;

// Solution For 1D Array 

// vector<int> findTwoElement(vector<int>& arr) {
//     int n = arr.size();
    
//     int repeating = -1;

//     for (int i = 0; i < n; i++) {
//         int val = abs(arr[i]);
        
//         if (arr[val - 1] > 0) {
//             arr[val - 1] = -arr[val - 1];
//         }
//         else {
//             repeating = val;
//         }
//     }
    
//     int missing = -1;
//     for (int i=0; i<n; i++) {
//         if (arr[i] > 0) {
//             missing = i+1;
//             break;
//         }
//     }
    
//     return {repeating, missing};
// }

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
  vector<int> ans(2,0);
  int n = grid.size();
  vector<int> cnt(n*n + 1, 0);
  for(int i=0;i<grid.size();i++){
      for(int j=0;j<grid[0].size();j++){
          cnt[grid[i][j]]++;
      }
  }

  for(int i=1;i<cnt.size();i++){
      if(cnt[i] == 2){
          ans[0] = i;
      }

      if(cnt[i] == 0){
          ans[1] = i;
      }
  }

  return ans;
}

int main()
{
  vector<vector<int>> grid = {{1, 2, 2}, {3, 6, 9}, {8, 5, 7}};
  vector<int> result = findMissingAndRepeatedValues(grid);
  cout << "Missing value: " << result[1] << endl;
  cout << "Repeated value: " << result[0] << endl;
  return 0;
}