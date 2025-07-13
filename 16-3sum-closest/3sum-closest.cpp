class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        int ans;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > target) {
                    k--;
                    while (k > j && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
                if (sum == target) {
                    return target;
                }
                if (abs(sum - target) < mini) {
                    ans = sum;
                    mini = abs(sum - target);
                }
            }
        }
        return mini == INT_MAX ? 0 : ans;
    }
};