//PROBLEM LINK
https://leetcode.com/problems/domino-and-tromino-tiling/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int numTilings(int N) {
        if(N == 1) return 1;
        if(N == 2) return 2;
        int dp[N+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=N;i++)
            dp[i] = ((2*dp[i-1])%m + dp[i-3])%m;
        return dp[N];
    }
};