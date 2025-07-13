class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int i = 0;
        while (i < nums.size() - 2) {
            if(nums[i] > 0) {
                break;
            }
            while (i > 0 &&  i < nums.size() - 2 && nums[i] == nums[i - 1]) {
                i++;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
                if (sum < 0) {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                } else {
                    k--;
                    while (k > j && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
            i++;
        }
        return result;
    }
};