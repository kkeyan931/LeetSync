class Solution {
public:
    int rec(vector<int>& nums, vector<vector<int>>& dp, int index,
            int prev_index) {

        if (index == nums.size()) {
            return 0;
        }

        if (dp[index][prev_index + 1] != -1) {
            return dp[index][prev_index + 1];
        }

        int include = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            include = 1 + rec(nums, dp, index + 1, index);
        }
        int exclude = rec(nums, dp, index + 1, prev_index);

        return dp[index][prev_index + 1] = max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(nums, dp, 0, -1);
    }
};