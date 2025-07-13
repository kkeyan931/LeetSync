class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        /* 1. mark the negative num to 0
           2. mark the index with negative value to mark the presence of integer
           3. traverse the array.
        */
        int n = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (index >= 0 && index < n) {
                nums[index] = nums[index] == 0 ? -1 * (index + 1) : -1 * abs(nums[index]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};