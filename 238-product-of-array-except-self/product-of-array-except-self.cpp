class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> result(n, 0);

        result[0] = nums[0];

        // prefix[i - 1] * suffix[i + 1] = product of the array except self

        // prefix of the array
        for(int i = 1; i < n; ++i) {
            result[i] = result[i - 1] * nums[i];
        }
        int suffix = 1;

        // suffix of the array
        for(int i = n - 1; i > 0; --i) {
            result[i] = result[i - 1] * suffix;
            suffix = suffix * nums[i];
        }

        result[0] = suffix;

        return result;
    }
};