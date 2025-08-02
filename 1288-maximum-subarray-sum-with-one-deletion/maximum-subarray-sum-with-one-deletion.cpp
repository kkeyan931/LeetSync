class Solution {
public:
    /*
     * 1186. Maximum Subarray Sum with One Deletion
     *
     * We keep two running DP states while scanning:
     *  - noDel: best subarray sum ending at current index with NO deletion
     * used.
     *  - oneDel: best subarray sum ending at current index WITH one deletion
     * used.
     *
     * Transitions:
     *  noDel = max(arr[i], noDel + arr[i])
     *  oneDel = max(oneDel + arr[i], prevNoDel)  // delete current element
     * arr[i]
     *
     * Answer is max over all i of max(noDel, oneDel).
     * Handles edge cases (single element, all negatives) naturally.
     */

    int maximumSum(vector<int>& arr) {
        const int n = (int)arr.size();
        // Initialize:
        // noDel = best sum ending at i with no deletion
        // oneDel = best sum ending at i with one deletion
        long long noDel = arr[0];
        long long oneDel =
            INT_MIN; // not available before we process at least two elements
        long long ans = arr[0];

        for (int i = 1; i < n; ++i) {
            long long x = arr[i];

            long long prevNoDel = noDel;

            // Classic Kadane for no deletion
            noDel = max(x, noDel + x);

            // For oneDel:
            // (a) extend an already-deleted subarray by adding x
            // (b) delete current x: take prevNoDel (subarray ending at i-1,
            // noDel)
            oneDel = max(oneDel + x, prevNoDel);

            // Track global best
            ans = max(ans, max(noDel, oneDel));
        }
        return (int)ans;
    }
};