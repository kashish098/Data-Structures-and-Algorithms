//PROBLEM LINK
//https://leetcode.com/problems/range-sum-query-2d-immutable/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
class NumMatrix {
public:
    int row, col;
    vector<vector<int>> dp;
    bool flag = false;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = row > 0 ? matrix[0].size() : 0;
        if(row ==0 || col == 0){
            flag = true;
        }
        else{
            int i, j;
        vector<int> v;
        for(i=0;i<row;i++){
            v.clear();
            for(j=0;j<col;j++){
                if(i == 0 && j == 0){
                    v.push_back(matrix[i][j]);
                }
                else if(i == 0){
                    v.push_back( v[j-1] + matrix[i][j]);
                }
                else if(j == 0){
                    v.push_back( dp[i-1][j] + matrix[i][j]);
                }
                else{
                    v.push_back(matrix[i][j] + v[j-1] + dp[i-1][j] - dp[i-1][j-1]);
                }
            }
            dp.push_back(v);
        }    
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(flag){
            return 0;
        }
        if(row1 == 0 && col1 == 0){
            return dp[row2][col2];
        }
        else if(row1 == 0){
            return dp[row2][col2] - dp[row2][col1-1];
        }
        else if(col1 == 0){
            return dp[row2][col2] - dp[row1-1][col2];
        }
        else{
            return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
        }
    }
};

