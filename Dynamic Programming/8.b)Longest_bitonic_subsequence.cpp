//PROBLEM LINK
// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution
{
public:
    vector<int> lis(vector<int> nums, int n)
    {
        int i, j;
        vector<int> dp(n, 1);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
            }
        }
        return dp;
    }

    vector<int> lds(vector<int> nums, int n)
    {
        int i, j;
        vector<int> dp(n, 1);

        for (i = n - 1; i >= 0; i--)
        {
            for (j = i + 1; j < n; j++)
            {
                if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
            }
        }
        return dp;
    }

    int LongestBitonicSequence(vector<int> nums)
    {
        int n = nums.size();
        int i, j, maxLen = 1;
        vector<int> dpLis = lis(nums, n);
        vector<int> dpLds = lds(nums, n);

        for (i = 0; i < n; i++)
        {
            maxLen = max(maxLen, dpLis[i] + dpLds[i] - 1);
        }
        return maxLen;
    }
}
