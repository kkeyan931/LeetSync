class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        int index = 0;

        int posStart = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        int ptr1 = posStart - 1;
        int ptr2 = posStart;
        int n2 = n - 1;

        while (ptr1 >= 0 && ptr2 <= n2) {
            int el1 = nums[ptr1] * nums[ptr1];
            int el2 = nums[ptr2] * nums[ptr2];
            if (el1 < el2) {
                result[index++] = el1;
                ptr1--;
            } else {
                result[index++] = el2;
                ptr2++;
            }
        }
        while (ptr1 >= 0) {
            result[index++] = nums[ptr1] * nums[ptr1];
            ptr1--;
        }
        while (ptr2 <= n2) {
            result[index++] = nums[ptr2] * nums[ptr2];
            ptr2++;
        }
        return result;
    }
};