class Solution {
public:
    int n;
    vector<int> a, b;
    vector<array<int, 2>> memo; // memo[i][pick]

    int dfs(int i, int pick) {
        int& ans = memo[i][pick];
        if (ans != -1)
            return ans;

        // Value picked at i
        long long cur = (pick == 0 ? a[i] : b[i]);

        // Base case: the subarray consisting of only i
        ans = 1;
        if (i == 0)
            return ans;

        // Try extending from i-1 with previous pick = 0 or 1
        long long prev0 = a[i - 1];
        long long prev1 = b[i - 1];

        // If prev pick was 0 (a[i-1]), can we extend?
        if (prev0 <= cur) {
            ans = max(ans, 1 + dfs(i - 1, 0));
        }
        // If prev pick was 1 (b[i-1]), can we extend?
        if (prev1 <= cur) {
            ans = max(ans, 1 + dfs(i - 1, 1));
        }
        return ans;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        n = (int)a.size();
        memo.assign(n, array<int, 2>{-1, -1});

        int best = 1;
        for (int i = 0; i < n; ++i) {
            best = max(best, dfs(i, 0));
            best = max(best, dfs(i, 1));
        }
        return best;
    }
};
