class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int ptr1 = 0;
        int ptr2 = 0;

        while(ptr2 < nums.size()) {
            if(nums[ptr1] == 0 && nums[ptr2] != 0) {
                swap(nums[ptr1], nums[ptr2]);
            }
            if(nums[ptr1] != 0) {
                ptr1++;
            }
            ptr2++;
        }
    }
};