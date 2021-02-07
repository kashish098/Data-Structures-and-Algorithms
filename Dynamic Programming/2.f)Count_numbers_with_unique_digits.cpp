//PROBLEM LINK
//https://leetcode.com/problems/count-numbers-with-unique-digits/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE


class Solution {
public:
    int dp[9];
    
    Solution(){
        dp[0] = 1;
        int d = 0, nd = 1;

        for(int i=1;i<=8;i++){
            d = d*10 + (i-1)*nd;
            nd = int(pow(10, i) - pow(10, i-1) - d);
            dp[i] = nd;
        }
        
        for(int i=1;i<=8;i++){
            dp[i] = dp[i-1] + dp[i];
        }
    }
    
    int countNumbersWithUniqueDigits(int n) {
        return dp[n];
    }
};