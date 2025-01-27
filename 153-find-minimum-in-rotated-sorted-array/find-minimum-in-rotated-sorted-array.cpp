class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0, end = n-1;

        int minEl = INT_MAX;
        while(start<=end) {
            int mid = start + ((end-start) / 2);

            if(nums[start]<=nums[mid]) {
                minEl = min(minEl, nums[start]);
                start = mid+1;
            } else {
                minEl = min(minEl, nums[mid]);
                end = mid-1;
            }
        }
        return minEl;
    }
};