class Solution {
public:
    int rec(string &text1, string &text2, vector<vector<int>> &dp, int i, int j) {
        if(i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + rec(text1, text2, dp, i - 1, j - 1);
        }
        return dp[i][j] = max(rec(text1, text2, dp, i - 1, j), rec(text1, text2, dp, i, j - 1));
    }
    int mem(string &text1, string &text2) {
        int n1 = text1.size() - 1;
        int n2 = text2.size() - 1;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return rec(text1, text2, dp, text1.size() - 1, text2.size() - 1);
    }
    int longestCommonSubsequence(string text1, string text2) {
        return mem(text1, text2);
    }
};