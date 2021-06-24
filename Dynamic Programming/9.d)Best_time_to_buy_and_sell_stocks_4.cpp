//PROBLEM LINK
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE


//Solution 1 ==> Space Complexity O(nk) Time Complexity O(kn^2);
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int t, i, j, temp, d = prices.size();
        if(d == 0 || k == 0) return 0;
        
        if(k> d/2){
            int maxProfit = 0;
            for(int i=0;i<d-1;i++){
                if(prices[i+1] - prices[i] > 0)
                    maxProfit += prices[i+1] - prices[i];
            }
            return maxProfit;
        }
        
        vector<vector<int> > dp(k+1, vector<int>(d,0));
        for(i=1;i<=k;i++){
            for(j=1;j<d;j++){
                temp = dp[i][j-1];
                for(t=0;t<j;t++){
                    temp  = (t == 0) ? max(temp,prices[j] - prices[t]): max(temp, dp[i-1][t-1] + prices[j] - prices[t]) ;
                }
                dp[i][j] = temp;
            }
        }
        return dp[k][d-1];
    }
};


// Solution-2 Time, Space COmplexity O(kn)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int t, i, j, temp, d = prices.size();
        if(d == 0 || k == 0) return 0;
        
        if(k> d/2){
            int maxProfit = 0;
            for(int i=0;i<d-1;i++){
                if(prices[i+1] - prices[i] > 0)
                    maxProfit += prices[i+1] - prices[i];
            }
            return maxProfit;
        }
        
        vector<vector<int> > dp(k+1, vector<int>(d,0));
        for(i=1;i<=k;i++){
            int maxTemp = -prices[0]; 
            for(j=1;j<d;j++){
                dp[i][j] = max(dp[i][j-1], maxTemp + prices[j]);
                maxTemp = max(maxTemp, dp[i-1][j-1] - prices[j]);
            }
        }
        return dp[k][d-1];
    }
};