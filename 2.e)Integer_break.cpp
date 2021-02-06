//PROBLEM LINK
https://leetcode.com/problems/integer-break/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = INT_MIN;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i], max(dp[i-j], i-j)*j);
            }
        }
        
        return dp[n];
    }
};