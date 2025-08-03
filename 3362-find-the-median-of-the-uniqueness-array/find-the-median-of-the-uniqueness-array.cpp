class Solution {
public:
    // Count the number of subarrays with at most k distinct elements.
    long long countAtMostKDistinct(const vector<int>& nums, int k) {
        if (k <= 0)
            return 0LL;
        unordered_map<int, int> freq;
        long long ans = 0;
        int n = (int)nums.size();
        int distinct = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            if (freq[nums[r]]++ == 0)
                ++distinct;        // new distinct enters window
            while (distinct > k) { // shrink to satisfy "at most k"
                if (--freq[nums[l]] == 0)
                    --distinct; // distinct leaves window
                ++l;
            }
            // All subarrays ending at r and starting from any index in [l..r]
            ans += (r - l + 1);
        }
        return ans;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        int n = (int)nums.size();
        // Total number of subarrays M and the median position K (1-indexed)
        long long M = 1LL * n * (n + 1) / 2;
        long long K = (M + 1) / 2;

        // Find D = number of distinct elements in the whole array
        unordered_set<int> s(nums.begin(), nums.end());
        int D = (int)s.size();

        // Binary search on t in [1..D]
        int lo = 1, hi = D, ans = D;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // candidate uniqueness
            long long cnt = countAtMostKDistinct(nums, mid);
            if (cnt >= K) {
                ans = mid; // mid is large enough; try smaller
                hi = mid - 1;
            } else {
                lo = mid + 1; // need more allowance on distinct
            }
        }
        return ans;
    }
};