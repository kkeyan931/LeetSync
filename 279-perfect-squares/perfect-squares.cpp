class Solution {
public:
    int rec(int i, int target, vector<int>& squares, vector<vector<int>>& dp) {
        if (target == 0)
            return 0;
        if (i < 0 || target < 0)
            return 1e9;

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = rec(i - 1, target, squares, dp);
        int take = 1e9;
        if (squares[i] <= target) {
            take = 1 + rec(i, target - squares[i], squares, dp); // unbounded
        }
        return dp[i][target] = min(take, notTake);
    }

    int mem(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }

        int m = squares.size();
        vector<vector<int>> dp(m, vector<int>(n + 1, -1));

        return rec(m - 1, n, squares, dp);
    }
    int table(int n) {

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= n; ++i) {
            for(int square = 1; square * square <= i; ++square) {
                if(square * square > i) {
                    break;
                }
                dp[i] = min(dp[i], dp[i - square * square] + 1);
            }
        }
        return dp[n];
    }
    int numSquares(int n) {
        // return mem(n);
        return table(n);
    }
};
