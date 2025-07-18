class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int last = nums[0];
        int ptr1 = 1, ptr2 = 1;

        while(ptr2 < nums.size()) {
            if(nums[ptr2] != last) {
                nums[ptr1] = nums[ptr2];
                ptr1++;
                last = nums[ptr2];
            }
            ptr2++;
        }
        return ptr1;
    }
};