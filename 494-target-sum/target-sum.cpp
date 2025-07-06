class Solution {
public:
    int rec(vector<int>& nums, int sum, int target, int index) {
        if (sum == target && index == nums.size()) {
            return 1;
        }
        if (index == nums.size()) {
            return 0;
        }

        return rec(nums, sum - nums[index], target, index + 1) +
               rec(nums, sum + nums[index], target, index + 1);
    }
    int pureRec(vector<int>& nums, int target) {
        int n = nums.size();
        return rec(nums, 0, target, 0);
    }

    int mem(vector<int>& nums, vector<vector<int>>& dp, int index, int target) {
        if (target < 0) {
            return 0;
        }
        if (index == 0) {
            if (target == 0 && nums[0] == 0) {
                return 2;
            }
            if (target == 0 || target == nums[0]) {
                return 1;
            }
            return 0;
        }

        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        return dp[index][target] =
                   mem(nums, dp, index - 1, target - nums[index]) +
                   mem(nums, dp, index - 1, target);
    }

    int dpWithSubset(vector<int>& nums, int target) {
        /*
            S1 - S2 = target;
            S1 + S2 = total;
            S1 - (total - S1) = target;
            S1 = (target + total) / 2;

            find number of subset with S1;
        */
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum + target) % 2 != 0) {
            return 0;
        }

        int n = nums.size();

        int S1 = (totalSum + abs(target)) / 2;

        vector<vector<int>> dp(n, vector<int>(S1 + 1, -1));

        return mem(nums, dp, n - 1, S1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return pureRec(nums, target);
        return dpWithSubset(nums, target);
    }
};