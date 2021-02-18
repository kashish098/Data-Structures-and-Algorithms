//PROBLEM LINK
//https://leetcode.com/problems/unique-paths-ii/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        int dp[rows][cols];
        int i, j;
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0){
                    dp[0][0] = !obstacleGrid[0][0];
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j == 0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};
