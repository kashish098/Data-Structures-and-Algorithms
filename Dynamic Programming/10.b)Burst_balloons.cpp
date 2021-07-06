//PROBLEM LINK
// https://leetcode.com/problems/burst-balloons/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution
{
public:
    int burstBalloons(int i, int j, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (j == i + 1)
        {
            return 0;
        }
        if (dp[i + 1][j + 1] != -1)
            return dp[i + 1][j + 1];
        int maxCoins = 0;
        int l = (i == -1) ? 1 : nums[i];
        int r = (j == n) ? 1 : nums[j];
        for (int k = i + 1; k < j; k++)
        {
            maxCoins = max(maxCoins, burstBalloons(i, k, n, nums, dp) + burstBalloons(k, j, n, nums, dp) + l * nums[k] * r);
        }
        return dp[i + 1][j + 1] = maxCoins;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return burstBalloons(-1, n, n, nums, dp);
    }
};