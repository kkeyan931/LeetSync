class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int dp[31][1001]; // n <= 30, target <= 1000

    int rec(int n, int k, int target) {
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 || target < 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int count = 0;
        for (int face = 1; face <= k; ++face) {
            count = (count + rec(n - 1, k, target - face)) % MOD;
        }

        return dp[n][target] = count;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return rec(n, k, target);
    }
};
