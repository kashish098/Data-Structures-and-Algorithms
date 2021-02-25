//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

//TOP-DOWN
int knapSackUtil(int W, int wt[], int val[], int n, vector<vector<int> > &dp){
    if(W == 0 || n == 0) return 0;
    if(dp[n][W] != -1) return dp[n][W];
    
    if(W-wt[n-1] >= 0){
        return dp[n][W] = max( knapSackUtil(W, wt, val, n-1, dp),
            knapSackUtil(W-wt[n-1], wt, val, n-1, dp) + val[n-1]);
    }
    return dp[n][W] = knapSackUtil(W, wt, val, n-1, dp);
    
}

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int> > dp(n+1, vector<int>(W+1, -1));
    return knapSackUtil(W, wt, val, n, dp);
}

//BOTTOM-UP
int knapSackUtil(int W, int wt[], int val[], int n, vector<vector<int> > &dp){
    int i, j;
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(j-wt[i-1] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
    
}

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int> > dp(n+1, vector<int>(W+1, -1));
    return knapSackUtil(W, wt, val, n, dp);
}
