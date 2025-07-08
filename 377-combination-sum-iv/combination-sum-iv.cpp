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
    int rec2(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;       // Base case: One valid way (empty combination)
        if (target < 0) return 0;        // Overshoot, invalid
        if (dp[target] != -1) return dp[target];  // Memoized result

        int count = 0;
        for (int num : nums) {
            count += rec2(nums, target - num, dp); // Pick num and recurse
        }
        return dp[target] = count;  // Save result
    }

    int mem(vector<int>& nums, int target) {
        // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // return rec(nums, dp, 0, target);

        vector<int> dp(target + 1, -1);
        return rec2(nums, target, dp);
    }
    int table(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1; // Base case: 1 way to make sum 0 (pick nothing)

        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        return mem(nums, target);
        // return table(nums, target);
    }
};