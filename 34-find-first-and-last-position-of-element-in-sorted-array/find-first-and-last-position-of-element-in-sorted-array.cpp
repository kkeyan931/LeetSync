class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n-1;

        while(start<=end) {
            int mid = start + ((end-start)/2);
            if(nums[mid] == target) {
                int ptr1 = mid, ptr2 = mid;
                while(ptr1>=0) {
                    if(nums[ptr1]==target) {
                        ptr1--;
                        continue;
                    }
                    break;
                }
                while(ptr2<=n-1) {
                    if(nums[ptr2]==target) {
                        ptr2++;
                        continue;
                    }
                    break;
                }
                return {ptr1+1, ptr2-1};
            } 
            else if(nums[mid]<target) start = mid+1;
            else end = mid-1;
        }
        return {-1, -1};
    }
};