class Solution {
public:
    int rec(vector<int> &coins,vector<vector<int>> &dp, int index, int amount) {
        if(amount == 0) {
            return 0;
        }
        if(index < 0 || amount < 0) {
            return INT_MAX - 1;
        }

        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int inc = rec(coins, dp, index, amount - coins[index]) + 1;
        int exc = rec(coins, dp, index - 1, amount);

        return dp[index][amount] = min(inc, exc);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int result = rec(coins, dp, n - 1, amount);
        return result == INT_MAX - 1 ? -1 : result;
    }
};