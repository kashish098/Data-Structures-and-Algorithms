//PROBLEM LINK
// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
// #define m 1000000007

static int m = 1e9 + 7;
class Solution
{
public:
    int pizza_cut(int i, int j, int k, int r, int c, vector<vector<int>> &t, vector<vector<vector<int>>> &dp)
    {

        if (t[i][j] < k)
            return 0;

        if (k == 1)
        {
            return (t[i][j] >= 1) ? 1 : 0;
        }

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        dp[i][j][k] = 0;

        int h, v;
        for (h = i + 1; h < r; h++)
        {
            if (t[i][j] - t[h][j] > 0 && t[h][j] >= k - 1)
            {
                dp[i][j][k] = (dp[i][j][k] % m + pizza_cut(h, j, k - 1, r, c, t, dp) % m) % m;
            }
        }

        for (v = j + 1; v < c; v++)
        {
            if (t[i][j] - t[i][v] > 0 && t[i][v] >= k - 1)
            {
                dp[i][j][k] = (dp[i][j][k] % m + pizza_cut(i, v, k - 1, r, c, t, dp) % m) % m;
            }
        }

        return dp[i][j][k];
    }

    int ways(vector<string> &pizza, int k)
    {
        int r = pizza.size();
        int c = pizza[0].length();
        int i, j;
        vector<vector<int>> t(r, vector<int>(c, 0));
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(k + 1, -1)));

        for (i = r - 1; i >= 0; i--)
        {
            for (j = c - 1; j >= 0; j--)
            {

                int diag = (i + 1 == r || j + 1 == c) ? 0 : t[i + 1][j + 1];
                int down = (i + 1 == r) ? 0 : t[i + 1][j];
                int right = (j + 1 == c) ? 0 : t[i][j + 1];
                t[i][j] = down + right - diag + (pizza[i][j] == 'A');
            }
        }
        return pizza_cut(0, 0, k, r, c, t, dp);
    }
};