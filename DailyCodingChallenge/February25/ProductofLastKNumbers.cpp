#include<bits/stdc++.h>
using namespace std;

// Using prefix of products in Time - O(1)

class ProductOfNumbers {
  public:
      vector<int>preprods;
  public:
      ProductOfNumbers() {
          preprods.push_back(1);
      }
      
      void add(int num) {
          if (num == 0) {
              preprods.clear();
              preprods.push_back(1);
              return;
          }
          preprods.push_back(preprods[preprods.size() - 1] * num);
  
      }
      
      int getProduct(int k) {
          if (k > preprods.size() - 1) return 0;
          return preprods[preprods.size() - 1] / preprods[preprods.size() - k - 1];
      }
  };

  // Iterating last k values in Time - O(k)

  class ProductOfNumbers {
    public:
        vector<int> arr;
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            arr.push_back(num);
        }
        
        int getProduct(int k) {
            int n = arr.size();
            if(n >= k){
                int ans = 1;
                for(int i=n-k;i<n;i++){
                    ans*= arr[i];
                }
                return ans;
            }
            return 0;
        }
    };
  
  /**
   * Your ProductOfNumbers object will be instantiated and called as such:
   * ProductOfNumbers* obj = new ProductOfNumbers();
   * obj->add(num);
   * int param_2 = obj->getProduct(k);
   */

int main()
{
  ProductOfNumbers* obj = new ProductOfNumbers();
  obj->add(3);
  obj->add(0);
  obj->add(2);
  obj->add(5);
  obj->add(4);
  cout << obj->getProduct(2) << endl;
  cout << obj->getProduct(3) << endl;
  cout << obj->getProduct(4) << endl;
  obj->add(8);
  cout << obj->getProduct(2) << endl;
  return 0;
}