// MEMORY LIMIT EXCEEDED
// Time Complexity: O(n * 2)
// Space Complexity: O(n * 2) + O(n)

// WATCH STRIVER'S VIDEO FOR BETTER UNDERSTANDING
class Solution
{
public:
    int f(int i, int buy, vector<int> prices, vector<vector<int>> &dp)
    {
        if (i == prices.size())
        {
            return 0;
        }

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if (buy)
        {
            profit = max(-prices[i] + f(i + 1, 0, prices, dp), 0 + f(i + 1, 1, prices, dp));
        }
        else
        {
            profit = max(prices[i] + f(i + 1, 1, prices, dp), 0 + f(i + 1, 0, prices, dp));
        }

        dp[i][buy] = profit;
        return profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};