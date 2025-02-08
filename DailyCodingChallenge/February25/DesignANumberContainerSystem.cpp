#include<bits/stdc++.h>
using namespace std;

// Optimised Solution in Logaritmic Time - O(logn)

class NumberContainers {
  unordered_map<int,int> idtonum;
  unordered_map<int,set<int>> numtoid;
public:
  NumberContainers() {
  }
  
  void change(int index, int number) {
     if(idtonum.contains(index)){
      int prev = idtonum[index];
      numtoid[prev].erase(index);
      if(numtoid[prev].empty()){
          numtoid.erase(prev);
      }
     }
     idtonum[index] = number;
     numtoid[number].insert(index);
  }
  
  int find(int number) {
      return (numtoid.contains(number))? *numtoid[number].begin() : -1;
  }
};

// Solution Using Linear Time - O(n)
class NumberContainers {
  public:
      unordered_map<int,int> mp;
      int ans;
      NumberContainers() {
          ans = -1;
      }
      
      void change(int index, int number) {
          mp[index] = number;
      }
      
      int find(int number) {
          int temp = INT_MAX;
          for(auto i: mp){
              if(i.second == number){
                  temp = min(i.first,temp);
              }
          }
  
          if(temp == INT_MAX){
              return ans;
          }
          return temp;
      }
  };

int main()
{
    NumberContainers nc;
    nc.change(1,2);
    nc.change(2,3);
    nc.change(3,4);
    nc.change(4,5);
    cout<<nc.find(2)<<endl;
    cout<<nc.find(3)<<endl;
    cout<<nc.find(4)<<endl;
    cout<<nc.find(5)<<endl;
    return 0;
}