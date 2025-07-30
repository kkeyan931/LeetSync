class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& dungeon, int i, int j) {
        if (i >= m || j >= n)
            return INT_MAX; // Out of bounds
        if (dp[i][j] != -1)
            return dp[i][j];

        // Base case: bottom-right cell
        if (i == m - 1 && j == n - 1) {
            return dp[i][j] = max(1, 1 - dungeon[i][j]);
        }

        int minNext = min(dfs(dungeon, i + 1, j), dfs(dungeon, i, j + 1));
        return dp[i][j] = max(1, minNext - dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        dp.assign(m, vector<int>(n, -1));
        return dfs(dungeon, 0, 0);
    }
};
