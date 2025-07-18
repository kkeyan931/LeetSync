class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int ptr1 = 0, ptr2 = 0;

        while(ptr2 < n) {
            if(nums[ptr1] != 0) {
                ptr1++;
            } else if(nums[ptr2] != 0 && nums[ptr1] == 0) {
                swap(nums[ptr1], nums[ptr2]);
                ptr1++;
            }
            ptr2++;
        }
    }
};