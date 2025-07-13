class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return countWhileMergeSort(prefix, 0, n + 1, lower, upper);
    }

    int countWhileMergeSort(vector<long long>& prefix, int left, int right,
                            int lower, int upper) {
        if (right - left <= 1)
            return 0;
        int mid = (left + right) / 2;
        int count = countWhileMergeSort(prefix, left, mid, lower, upper) +
                    countWhileMergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid, t = mid;
        vector<long long> temp;
        for (int i = left; i < mid; ++i) {
            while (k < right && prefix[k] - prefix[i] < lower)
                ++k;
            while (j < right && prefix[j] - prefix[i] <= upper)
                ++j;
            count += j - k;
        }

        // Merge step to keep prefix sorted
        vector<long long> sorted;
        int i = left, p = mid;
        while (i < mid && p < right) {
            if (prefix[i] < prefix[p])
                sorted.push_back(prefix[i++]);
            else
                sorted.push_back(prefix[p++]);
        }
        while (i < mid)
            sorted.push_back(prefix[i++]);
        while (p < right)
            sorted.push_back(prefix[p++]);
        copy(sorted.begin(), sorted.end(), prefix.begin() + left);

        return count;
    }
};
