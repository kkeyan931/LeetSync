class Solution {
public:
    int n, m;
    // -1 = unknown, 0 = false, 1 = true
    vector<vector<int>> memo;

    bool dfs(string &s, string &p, int i, int j) {
        if (j == m)
            return i == n; // both consumed
        if (memo[i][j] != -1)
            return memo[i][j];

        bool first = (i < n) && (p[j] == s[i] || p[j] == '.');

        bool ans = false;
        if (j + 1 < m && p[j + 1] == '*') {
            // 1) take zero of p[j]  2) take one and stay on j
            ans = dfs(s, p, i, j + 2) || (first && dfs(s, p, i + 1, j));
        } else {
            ans = first && dfs(s, p, i + 1, j + 1);
        }
        return memo[i][j] = ans;
    }

    bool isMatch(string S, string P) {
        n = S.size();
        m = P.size();
        memo.assign(n + 1, vector<int>(m + 1, -1));
        return dfs(S, P, 0, 0);
    }
};
