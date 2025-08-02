class Solution {
public:
    int rec(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row,
            int col) {
        if (col < 0 || col >= matrix.size()) {
            return INT_MAX / 4;
        }
        if (row == 0) {
            return matrix[0][col];
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int up = rec(matrix, dp, row - 1, col);
        int topLeft = rec(matrix, dp, row - 1, col - 1);
        int topRight = rec(matrix, dp, row - 1, col + 1);

        return dp[row][col] = min({up, topLeft, topRight}) + matrix[row][col];
    }
    int mem(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mini = INT_MAX;
        for (int i = 0; i < n; ++i) {
            mini = min(mini, rec(matrix, dp, n - 1, i));
        }
        return mini;
    }
    int table(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n == 1)
            return matrix[0][0];

        int ans = INT_MAX;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                matrix[i][j] +=
                    min({matrix[i - 1][j], matrix[i - 1][max(0, j - 1)],
                         matrix[i - 1][min(n - 1, j + 1)]});

                if (i == n - 1) {
                    ans = min(ans, matrix[i][j]);
                }
            }
        }

        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) { 
        // return mem(matrix); 
        return table(matrix);
    }
};