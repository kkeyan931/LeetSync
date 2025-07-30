class Solution {
public:
    int rec(string& s, string& t, vector<vector<int>>& dp, int i, int j) {
        if (i == s.size() || j == t.size()) {
            return j == t.size() ? 1 : 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            return dp[i][j] =
                       rec(s, t, dp, i + 1, j) + rec(s, t, dp, i + 1, j + 1);
        }
        return dp[i][j] = rec(s, t, dp, i + 1, j);
    }
    int mem(string& s, string& t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return rec(s, t, dp, 0, 0);
    }
    int numDistinct(string s, string t) { return mem(s, t); }
};