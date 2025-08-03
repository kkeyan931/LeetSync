class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        /*
            1. Get the numbers from the both sides included that sum up to x
            2. Find the max subarray maxSize = sum(nums) - x
            3. sum(Remaining elemenets) = x =>  both sides elements included
            4. n - maxSize => ans
        */

        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0ll);
        int target = totalSum - x;

        int sum = 0;
        int maxSize = -1;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (left < n && sum > target) {
                sum -= nums[left];
                left++;
            }
            if (sum == target) {
                maxSize = max(maxSize, right - left + 1);
            }
        }

        return maxSize == -1 ? -1 : n - maxSize;
    }
};