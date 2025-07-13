class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k == 0 || k == 1) {
            return 0;
        }

        int ptr1 = 0;
        int ptr2 = 0;

        int count = 0;

        int prod = 1;
        while (ptr2 < nums.size()) {
            if (nums[ptr2] < k) {
                count++;
            }
            prod *= nums[ptr2];

            if (prod < k) {
                count += ptr2 - ptr1;
            }
            while (prod >= k && ptr1 < nums.size()) {
                prod /= nums[ptr1];
                ptr1++;
                if (prod < k && ptr1 < ptr2) {
                    count += ptr2 - ptr1;
                }
            }
            ptr2++;
        }
        return count;
    }
};