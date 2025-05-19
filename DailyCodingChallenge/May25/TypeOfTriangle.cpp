#include<bits/stdc++.h>
using namespace std;

string triangleType(vector<int>& nums) {
        int tsa = nums[0] + nums[1], tsb = nums[1] + nums[2], tsc = nums[0] + nums[2];
        if(tsa > nums[2] && tsb > nums[0] && tsc > nums[1]){
            if(nums[0] == nums[1] && nums[0] == nums[2]){
                return "equilateral";
            }else if(nums[0]!= nums[1] && nums[1] != nums[2] && nums[2] != nums[0]){
                return "scalene";
            }else{
                return "isosceles";
            }
        }

        return "none";
    }

int main()
{
    vector<int> nums = {2, 2, 3};
    cout << triangleType(nums) << endl;
    return 0;
}