class Solution {
public:
    vector<long long> memo;
    long long solve(int k) {
        if (k <= 1)
            return 1;
        if (memo[k] != -1)
            return memo[k];

        long long ans = 0;
        for (int root = 1; root <= k; ++root) {
            ans += solve(root - 1) * solve(k - root);
        }
        return memo[k] = ans;
    }
    int numTrees(int n) {
        memo.assign(n + 1, -1);
        return static_cast<int>(solve(n));
    }
};