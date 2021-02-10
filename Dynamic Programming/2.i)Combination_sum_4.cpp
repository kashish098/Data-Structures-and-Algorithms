//PROBLEM LINK
//https://leetcode.com/problems/combination-sum-iv/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

#define ll unsigned long long
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int i, j;
        ll dp[target+1];
        for(i=0;i<=target;i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        
        for(i=1;i<=target;i++){
            for(j=0;j<n;j++){
                if(i>=nums[j]){
                    dp[i] += dp[i - nums[j]];
                }
                    
            }
        }
        
        return dp[target];
    }
};


