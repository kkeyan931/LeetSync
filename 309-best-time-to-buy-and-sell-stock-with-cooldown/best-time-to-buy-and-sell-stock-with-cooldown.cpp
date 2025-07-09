class Solution {
public:
    int rec(vector<int> &price, vector<vector<int>> &dp, int index, bool canBuy) {
        if(index >= price.size()) {
            return 0;
        }
        if(dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }
        if(canBuy) {
             int buy = -price[index] + rec(price, dp, index + 1, false);
             int skip = rec(price, dp, index + 1, true);
             return dp[index][canBuy] = max(buy, skip);
        } else {
            int sell =  price[index] + rec(price, dp, index + 2, true);
            int skip = rec(price, dp, index + 1, false);
            return dp[index][canBuy] = max(sell, skip);
        }
    }
    int mem(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return rec(prices, dp, 0, true);
    }
    int maxProfit(vector<int>& prices) {
        return mem(prices);
    }
};