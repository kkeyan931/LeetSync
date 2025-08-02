class Solution {
public:
    int markWithNegative(vector<int>& nums) {
        /* 1. mark the negative num to 0
           2. mark the index with negative value to mark the presence of integer
           3. traverse the array.
        */
        int n = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (index >= 0 && index < n) {
                nums[index] =
                    nums[index] == 0 ? -1 * (index + 1) : -1 * abs(nums[index]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
    int cycleSort(vector<int>& nums) {
        int n = nums.size();

        // Use cycle sort to place positive elements smaller than n
        // at the correct index
        int i = 0;
        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        // Iterate through nums
        // return smallest missing positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all elements are at the correct index
        // the smallest missing positive number is n + 1
        return n + 1;
    }
    int firstMissingPositive(vector<int>& nums) {
        return cycleSort(nums);
    }
};