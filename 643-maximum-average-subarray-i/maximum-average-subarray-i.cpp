class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum = 0;

        for(int i = 0; i < k; ++i) {
            sum = sum + nums[i];
        }

        double result = (double) sum / (double) k;

        for(int i = k; i < nums.size(); ++i) {
            sum = sum + nums[i];
            sum = sum - nums[i-k];
            
            result = max(result, (double) sum / (double) k);
        }
        return result;
    }
};