class Solution {
public:
    int rec(vector<int>& nums, vector<vector<int>>& dp, int index, int target) {
        
        if (target == 0) {
            return 1;
        }
        if (index == nums.size()) {
            return 0;
        }
        if (target < 0) {
            return 0;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        return dp[index][target] =
                   rec(nums, dp, 0, target - nums[index]) +
                   rec(nums, dp, index + 1, target);
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return rec(nums, dp, 0, target);
    }
};