class Solution {
public:
    int rec(vector<int> &dp, int n) {
        if(n <= 2) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = rec(dp, n - 1) + rec(dp, n - 2);
    }
    int mem(int n) {
        vector<int> dp(n + 1, -1);
        return rec(dp, n);
    }
    int table(int n) {

        if(n <= 2) {
            return n;
        }
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int space(int n) {
        if(n <= 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        int c;
        for(int i = 3; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
    int climbStairs(int n) {
        // return mem(n);
        // return table(n);
        return space(n);
    }
};