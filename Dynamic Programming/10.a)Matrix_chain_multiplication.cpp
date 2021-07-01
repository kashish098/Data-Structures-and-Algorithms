//PROBLEM LINK
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution{
public:

    int matrixMultiplicationUtil(int i, int j, int arr[], vector<vector<int> > &dp){
        if(j == i+1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int k, minMultiplications = INT_MAX;
        for(k=i+1;k<j;k++){
            minMultiplications = min(minMultiplications, matrixMultiplicationUtil(i,k,arr,dp) + matrixMultiplicationUtil(k,j,arr,dp) + arr[i]*arr[k]*arr[j]);
        }
        return dp[i][j] = minMultiplications;
    }
    int matrixMultiplication(int N, int arr[])
    {
        if(N < 2) return 0;
        vector<vector<int> > dp(N, vector<int>(N, -1));
        return matrixMultiplicationUtil(0, N-1, arr, dp);
    }
};

