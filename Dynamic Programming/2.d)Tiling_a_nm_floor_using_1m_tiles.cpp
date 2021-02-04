//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

#define mod 1000000007;
class Solution{
	public:
	int countWays(int n, int m){
	    if(m > n) return 1;
	    int dp[n+1];
	    dp[0] = 1;
	    int i;
	    for(i=1;i<=n;i++){
	        if(i - m >=0){
	            dp[i] = (dp[i-1] + dp[i - m])%mod;
	        }
	        else{
	            dp[i] = dp[i-1];
	        }
	    }
	    return dp[n];
    }
};