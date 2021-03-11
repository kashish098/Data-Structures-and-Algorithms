//COIN CHANGE 1
//PROBLEM LINK
//https://leetcode.com/problems/maximum-product-subarray/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++){
            res = max(res + nums[i], nums[i]);
            ans = max(ans, res);
        }
        return ans;
    }
};