class Solution {
public:
    int usingBinarySearch(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxBeauty = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Find the farthest index where the value is within the range
            // [nums[i], nums[i] + 2*k]
            int upperBound =
                upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k) -
                nums.begin() - 1;
            // Update the maximum beauty based on the current range
            maxBeauty = max(maxBeauty, upperBound - i + 1);
        }
        return maxBeauty;
    }
    int usingSlidingWindow(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int right = 0;
        int maxBeauty = 0;

        for (int left = 0; left < nums.size(); left++) {
            // Expand the right pointer while the range condition is met
            while (right < nums.size() && nums[right] - nums[left] <= 2 * k) {
                right++;
            }
            maxBeauty = max(maxBeauty, right - left);
        }
        return maxBeauty;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        // return usingBinarySearch(nums, k);
        return usingSlidingWindow(nums, k);
    }
};