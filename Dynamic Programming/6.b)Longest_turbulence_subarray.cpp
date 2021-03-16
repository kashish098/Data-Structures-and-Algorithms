class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        int dp[n][2];

        dp[0][0] = dp[0][1] = 1;

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                dp[i][0] = dp[i][1] = 1;
            }
            else if(nums[i] > nums[i-1]){
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = 1;
            }
            else{
                dp[i][0] = 1;
                dp[i][1] = dp[i-1][0] + 1;
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i][0] > ans)
                ans = dp[i][0];

            if(dp[i][1] > ans)
                ans = dp[i][1];    
        }
        return ans;
    }
};