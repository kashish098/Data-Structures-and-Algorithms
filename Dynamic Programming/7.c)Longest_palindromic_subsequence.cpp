//PROBLEM LINK
//https://leetcode.com/problems/longest-palindromic-subsequence/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int i, j, n = s.length();
        vector<vector<int> > dp(n, vector<int>(n,0));
        
        for(i=n-1;i>=0;i--){
            for(j=i;j<n;j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};