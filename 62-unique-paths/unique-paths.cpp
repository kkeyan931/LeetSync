class Solution {
public:
    int rec(vector<vector<int>>& dp, int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }
        if (m <= 0 || n <= 0) {
            return 0;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        return dp[m][n] = rec(dp, m - 1, n) + rec(dp, m, n - 1);
    }
    int mem(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return rec(dp, m, n);
    }
    int uniquePaths(int m, int n) { return mem(m, n); }
};