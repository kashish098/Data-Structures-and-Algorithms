//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
int LongestRepeatingSubsequence(string str)
{
    int i, j, n = str.length();
    int dp[n + 1][n + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str[i - 1] == str[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}