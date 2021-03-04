//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
int knapsack(int value[], int wt[], int items, int weight){
    int dp[weight+1]={0}, i, j;
    
    for(i=1;i<=weight;i++){
        for(j=0;j<items;j++){
            
            if(i - wt[j] >= 0)
                dp[i] = max(dp[i],dp[i-wt[j]]+value[j]);
            
        }
    }
    return dp[weight];
}