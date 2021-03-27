//PROBLEM LINK
//https://leetcode.com/problems/longest-common-subsequence/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        if(m == 0 || n == 0) return 0;
        vector<vector<short>> dp(m+1, vector<short>(n+1));

        int i,j;
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];  
    }
};