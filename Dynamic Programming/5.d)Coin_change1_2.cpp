//COIN CHANGE 1
//PROBLEM LINK
//https://leetcode.com/problems/coin-change/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return -1;
        
        if(amount == 0){
            return 0;
        }
        
        int i,j;
        int dp[amount+1];
        
        dp[0] = 0;
        for(i=1;i<=amount;i++){
            dp[i] = -1;
        }
        
        
        for(i=1;i<=amount;i++){
            for(j=0;j<coins.size();j++){
                if(i-coins[j] >=0 && dp[i-coins[j]] != -1){
                    if(dp[i] == -1){
                        dp[i] = 1 + dp[i-coins[j]];
                    }
                    else{
                        dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                    }
                }
            }
        }
        return dp[amount];
    }
};

//Coin Change 2
//https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len, i, j, k;
        len = coins.size();
        int dp[len+1][amount+1];

        for(i=0;i<=len;i++){
            for(j=0;j<=amount;j++){
                
                +
                else if(i == 0){
                    dp[i][j] = 0;
                } 
                else{
                    if(j - coins[i-1] >= 0){
                        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[len][amount];      
    }
};