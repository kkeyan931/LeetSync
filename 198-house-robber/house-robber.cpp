class Solution {
public:
    int rec(vector<int> &nums, vector<int> &dp, int index) {
        if(index < 0) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        } 
        int take = rec(nums, dp, index  - 2) + nums[index];
        int notTake = rec(nums, dp, index - 1);

        return dp[index] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1, -1);

        return rec(nums, dp, n - 1);
    }
};