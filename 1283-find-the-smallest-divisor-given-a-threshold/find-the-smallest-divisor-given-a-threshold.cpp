class Solution {
public:
    bool canSum(vector<int> &nums, int divisor, int threshold) {
        long long sum = 0;
        for(auto &num : nums) {
            sum += (num+divisor-1)/divisor;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int start = 1, end = *(max_element(nums.begin(), nums.end()));

        int result = end;
        while(start<=end) {
            int mid = start + (end-start)/2;
            
            if(canSum(nums, mid, threshold)) {
                result = min(result, mid);
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return result;
    }
};