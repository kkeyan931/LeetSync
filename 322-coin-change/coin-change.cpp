class Solution {
public:
    int rec(vector<int> &coins, vector<vector<int>> &dp, int index, int amount) {
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return INT_MAX;
        }
        if(index == coins.size()) {
            return INT_MAX;
        }

        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int taken = rec(coins, dp, index, amount - coins[index]);
        taken = taken == INT_MAX ? INT_MAX : taken + 1;
        int notTaken = rec(coins, dp, index + 1, amount);

        return dp[index][amount] = min(taken, notTaken);
    }
    int mem(vector<int> &coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int result = rec(coins, dp, 0, amount);
        return result == INT_MAX ? -1 : result;
    }
    int coinChange(vector<int>& coins, int amount) {
        return mem(coins, amount);
    }
};