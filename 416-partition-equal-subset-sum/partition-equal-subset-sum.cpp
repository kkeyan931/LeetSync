class Solution {
public:
    int rec(vector<int>& nums, vector<vector<int>>& dp, int index, int target) {
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        if (index == nums.size()) {
            return false;
        }

        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        int take = rec(nums, dp, index + 1, target - nums[index]);
        int notTake = rec(nums, dp, index + 1, target);

        return dp[index][target] = take || notTake;
    }
    bool mem(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) {
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(total / 2 + 1, -1));
        return rec(nums, dp, 0, total / 2);
    }
    bool canPartition(vector<int>& nums) { return mem(nums); }
};