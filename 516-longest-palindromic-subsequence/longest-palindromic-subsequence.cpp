class Solution {
public:
    int rec(string& s, vector<vector<int>>& dp, int i, int j) {
        if (i == j) {
            return 1;
        }
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == s[j]) {
            return dp[i][j] = rec(s, dp, i + 1, j - 1) + 2;
        }
        return dp[i][j] = max(rec(s, dp, i + 1, j), rec(s, dp, i, j - 1));
    }
    int mem(string& s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return rec(s, dp, 0, s.size() - 1);
    }
    int longestPalindromeSubseq(string s) { return mem(s); }
};