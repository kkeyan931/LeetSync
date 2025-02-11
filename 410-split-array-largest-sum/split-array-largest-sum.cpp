class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxAllowed) {
        int sumSoFar = nums[0], count = 1;

        for(int i=1;i<nums.size();++i) {
            if(sumSoFar+nums[i]<=maxAllowed) {
                sumSoFar+=nums[i];
            } else {
                count++;
                sumSoFar = nums[i];
            }
            if(count>k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int maxElement = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int start = maxElement, end = sum;

        int result = sum;
        while(start <= end) {
            int mid = start + ((end-start)/2);

            if(canSplit(nums, k, mid)) {
                result = min(result, mid);
                end = mid - 1;
            } else {
                start = mid+1;
            }
        }

        return result;
    }
};