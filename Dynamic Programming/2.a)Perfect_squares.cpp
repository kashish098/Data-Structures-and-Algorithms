class Solution {
public:
    int numSquares(int n) {
        int i,j;        
        int dp[n+1];
        dp[0] = 0;
        for(i=1;i<=n;i++){
            dp[i] = INT_MAX;
        }
        
        for(i=1;i<=n;i++){
            for(j=1;j*j<=i;j++){
                dp[i] = min(dp[i], 1+ dp[i - j*j]);
            }    
        }
        
        return dp[n];
    }
};