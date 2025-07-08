class Solution {
public:
    bool rec(vector<int> &nums, vector<vector<int>> &dp, int index, int target) {
        if(target == 0) {
            return true;
        }
        if(index == nums.size()) {
            return false;
        }
        if(target < 0) {
            return false;
        }

        if(dp[index][target] != -1) {
            return dp[index][target];
        }

        bool take = rec(nums, dp, index + 1, target - nums[index]);
        bool notTake = rec(nums, dp, index + 1, target);

        return dp[index][target] = take || notTake;
    }
    bool mem(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total % 2 != 0) {
            return false;
        }
        int target = total / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return rec(nums, dp, 0, target);
    }
    bool canPartition(vector<int>& nums) {
        return mem(nums);
    }
};