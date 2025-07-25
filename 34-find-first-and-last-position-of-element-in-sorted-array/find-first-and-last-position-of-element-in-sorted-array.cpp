class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);

        if (lb == n || nums[lb] != target) {
            return {-1, -1};
        }
        return {lb, ub - 1};
    }
};