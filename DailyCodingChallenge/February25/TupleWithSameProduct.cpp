#include<bits/stdc++.h>
using namespace std;

// Using Optimised Solution

int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();

        vector<int> pairProducts;

        int totalNumberOfTuples = 0;

        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                 secondIndex++) {
                pairProducts.push_back(nums[firstIndex] * nums[secondIndex]);
            }
        }

        sort(pairProducts.begin(), pairProducts.end());

        int lastProductSeen = -1;
        int sameProductCount = 0;

        for (int productIndex = 0; productIndex < pairProducts.size();
             productIndex++) {
            if (pairProducts[productIndex] == lastProductSeen) {
                
                sameProductCount++;
            } else {
                
                int pairsOfEqualProduct =
                    (sameProductCount - 1) * sameProductCount / 2;

                totalNumberOfTuples += 8 * pairsOfEqualProduct;

                // Update lastProductSeen and reset sameProductCount
                lastProductSeen = pairProducts[productIndex];
                sameProductCount = 1;
            }
        }

        int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
        totalNumberOfTuples += 8 * pairsOfEqualProduct;

        return totalNumberOfTuples;
    }

// Using Unordered Map with Time - O(n^2)
int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();

        if(n<4){
            return 0;
        }

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto i:mp){
            if(i.second>1)
            ans += 4*(i.second)*(i.second - 1); 
        }
        return ans;
    }

// Using Sort and Two Pointers on Pairs With Time - O(n^2)
int tupleSameProduct(vector<int>& nums) {
        if(nums.size()<4){
            return 0;
        }

        int count = 0;
        sort(nums.begin(),nums.end());

        vector<pair<int,int>> pa;
        for(int i=0;i<nums.size();i++){
            for(int j=i+3;j<nums.size();j++){
                pa.push_back(make_pair(i,j));
            }
        }

        for(int i=0;i<pa.size();i++){
            pair<int,int> t = pa[i];
            int a = t.first, b = t.second;
            int c = a+1, d = b-1;
            int ab = nums[a] * nums[b];
            while(c<d){ 
                int cd = nums[c] * nums[d];
                if(cd == ab){
                    count++;
                    c++;
                    d--;
                }else if(cd < ab){
                    c++;
                }else{
                    d--;
                } 
            } 
        }

        int ans = count * 8;
        return ans;
    }

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  cout << "The number of tuples that have the same product as any 4 distinct numbers is " << tupleSameProduct(nums) << endl;

  return 0;
}