class Solution {
public:
    int iteration(vector<int> &nums, int target) {

        int start = 0, end = nums.size() - 1;

        while(start<=end) {
            int mid = start+((end-start) / 2);

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid]<target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return -1;
    } 
    int search(vector<int>& nums, int target) {
        return iteration(nums, target);
    }
};