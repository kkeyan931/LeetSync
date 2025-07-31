class Solution {
public:
    int dp[101][101];

    int solve(string& s, int i, int j) {
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;

        for (int k = i; k < j; ++k) {
            res = min(res, solve(s, i, k) + solve(s, k + 1, j));
        }

        return dp[i][j] = s[i] == s[j] ? res - 1 : res;
    }

    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size() - 1);
    }
};