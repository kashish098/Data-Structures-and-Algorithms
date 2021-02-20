//PROBLEM LINK
//https://leetcode.com/problems/maximal-square/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        int maxsize = 0;
        
        int dp[rows][col];
        int i, j;
        
        for(i=0;i<rows;i++){
            dp[i][0] = matrix[i][0] - '0';
            maxsize = max(maxsize, dp[i][0]);
        }
        
        for(i=0;i<col;i++){
            dp[0][i] = matrix[0][i] - '0';
            maxsize = max(maxsize, dp[0][i]);
        }
        
        for(i=1;i<rows;i++){
            for(j=1;j<col;j++){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    maxsize = max(maxsize, dp[i][j]);
                }
                
            }
        }
        return maxsize*maxsize;
    }
};

