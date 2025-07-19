class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            int temp_max = max({curr, curr * max_so_far, curr * min_so_far});
            int temp_min = min({curr, curr * max_so_far, curr * min_so_far});

            max_so_far = temp_max;
            min_so_far = temp_min;

            result = max(result, max_so_far);
        }

        return result;
    }
};