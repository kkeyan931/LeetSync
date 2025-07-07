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

    int mem(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(nums, dp, 0, -1);
    }
    int table(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
    int binarySearch(vector<int>& nums) {
        vector<int> temp;
        for (auto num : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if (it == temp.end()) {
                temp.push_back(num);
            } else {
                *it = num;
            }
        }
        return temp.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // return mem(nums);
        // return table(nums);
        return binarySearch(nums);
    }
};