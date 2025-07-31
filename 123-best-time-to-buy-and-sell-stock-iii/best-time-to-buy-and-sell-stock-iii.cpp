class Solution {
public:
    int rec(vector<int>& price, vector<vector<vector<int>>>& dp, int index,
            bool canBuy, int k) {
        if (index >= price.size()) {
            return 0;
        }
        if (k <= 0) {
            return 0;
        }
        if (dp[index][canBuy][k] != -1) {
            return dp[index][canBuy][k];
        }
        if (canBuy) {
            int buy = -price[index] + rec(price, dp, index + 1, false, k);
            int skip = rec(price, dp, index + 1, true, k);
            return dp[index][canBuy][k] = max(buy, skip);
        } else {
            int sell = price[index] + rec(price, dp, index + 1, true, k - 1);
            int skip = rec(price, dp, index + 1, false, k);
            return dp[index][canBuy][k] = max(sell, skip);
        }
    }
    int mem(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return rec(prices, dp, 0, true, 2);
    }
    int maxProfit(vector<int>& prices) { return mem(prices); }
};