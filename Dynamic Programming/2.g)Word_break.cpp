//PROBLEM LINK
//https://leetcode.com/problems/word-break/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        bool dp[len+1];
        dp[0] = true;
        int i, j;

        for(i=1;i<=len;i++){
            dp[i] = false;
        }

        for(i=1;i<=len;i++){
            for(j=1;j<=i;j++){
                if( find(wordDict.begin(), wordDict.end(), s.substr(i-j, j)) != wordDict.end() && dp[i-j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
        
    }
};