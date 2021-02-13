//PROBLEM LINK
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

//TOP-DOWN APPROACH
#define m 1000000007
class Solution {
public:

    int numRollsToTargetUtil(int target, int d, int f, vector<int> dp[]){
        if(target == 0 && d == 0){
            return 1;
        }
        if(target <= 0 || d<=0){
            return 0;
        }

        if(dp[target][d] != -1){
            return dp[target][d];
        }

        int count = 0;
        for(int i=1;i<=f;i++){
            count = (count + numRollsToTargetUtil(target - i, d-1, f, dp) ) % m;
        }
        return dp[target][d] = count;
    }

    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp[target+1];
        for(int i=0;i<=target;i++){
            for(int j=0;j<=d;j++){
                dp[i].push_back(-1);
            }
        }
        return numRollsToTargetUtil(target, d, f, dp);
    }
};


//BOTT0M-UP APPROACH
#define m 1000000007
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int i, j, dp[d+1][target+1];
        dp[0][0] = 1;

        for(i=0;i<=d;i++){
            for(j=0;j<=target;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 0;
                    for(int k = 1;k<=f && j - k >= 0;k++){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k])%m;
                    }
                }
            }
        }
        return dp[d][target];
    }
};