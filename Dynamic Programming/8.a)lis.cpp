//PROBLEM LINK
// https://leetcode.com/problems/longest-increasing-subsequence/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution
{
public:
    int lengthOfLIS(vector<int> &a)
    {
        int i, j, maxLen = 1, n = a.size();
        int dp[n];
        for (i = 0; i < n; i++)
            dp[i] = 1;

        for (i = 1; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (a[j] < a[i] && 1 + dp[j] > dp[i])
                    dp[i] = 1 + dp[j];
            }
        }

        for (i = 0; i < n; i++)
            if (dp[i] > maxLen)
                maxLen = dp[i];

        return maxLen;
    }
};