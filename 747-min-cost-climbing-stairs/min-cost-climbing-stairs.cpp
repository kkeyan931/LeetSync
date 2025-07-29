class Solution {
public:
    int rec(vector<int>& cost, vector<int> &dp, int index) {
        if (index == 0 || index == 1)
            return 0;

        if(dp[index] != -1) {
            return dp[index];
        }
        
        int step1 = rec(cost, dp, index - 1) + cost[index - 1];
        int step2 = rec(cost, dp, index - 2) + cost[index - 2];

        return dp[index] = min(step1, step2);
    }

    int mem(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        return rec(cost, dp, cost.size());
    }

    int table(vector<int> &cost) {
        vector<int> dp(cost.size() + 1);

        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.size(); ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // return mem(cost);
        return table(cost);
    }
};
