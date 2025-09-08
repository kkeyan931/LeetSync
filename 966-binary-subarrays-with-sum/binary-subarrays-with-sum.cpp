class Solution {
public:
    int usingPrefixSum(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;
        unordered_map<int, int> freq;

        for (int num : nums) {
            currentSum += num;
            if (currentSum == goal) {
                totalCount++;
            }

            // Check if there is any prefix sum that can be subtracted from the
            // current sum to get the desired goal
            if (freq.find(currentSum - goal) != freq.end()) {
                totalCount += freq[currentSum - goal];
            }

            freq[currentSum]++;
        }

        return totalCount;
    }
    int slidingWindowAtMost(vector<int>& nums, int goal) {
        int start = 0, currentSum = 0, totalCount = 0;

        // Iterate through the array using a sliding window approach
        for (int end = 0; end < nums.size(); end++) {
            currentSum += nums[end];

            // Adjust the window by moving the start pointer to the right
            // until the sum becomes less than or equal to the goal
            while (start <= end && currentSum > goal) {
                currentSum -= nums[start++];
            }

            // Update the total count by adding the length of the current
            // subarray
            totalCount += end - start + 1;
        }
        return totalCount;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // return usingPrefixSum(nums, goal);
        return slidingWindowAtMost(nums, goal) -
               slidingWindowAtMost(nums, goal - 1);
    }
};