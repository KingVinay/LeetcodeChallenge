#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(i<=k){
            if(nums[i]==0){
                swap(nums[i++], nums[j++]);
            }
            else if(nums[i]==2){
                swap(nums[k--],nums[i]);
            }
            else{
                i++;
            }
        }
    }

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}