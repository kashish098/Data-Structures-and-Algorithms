//PROBLEM LINK
//https://leetcode.com/problems/partition-equal-subset-sum/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    bool findSubset(vector<int>& nums, int sum){
        cout<<sum<<endl;
        if(sum == 0) return true;
        if(nums.size() == 0) return false;
        
        int i, j, n = nums.size();
        bool dp[n +1][sum +1];
        
        for(i=0;i<=n;i++){
            for(j=0;j<=sum;j++){
                if(j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0){
                    dp[i][j] = false;
                }
                else if(j - nums[i-1] >= 0){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums){
            sum += num;
        }
        if(sum & 1) return false;
        return findSubset(nums, sum/2);
    }
};