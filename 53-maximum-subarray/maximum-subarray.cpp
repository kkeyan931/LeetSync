class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int preMax = 0;
        int overallMax = INT_MIN;

        for(int i=0;i<n;++i) {
            preMax+=nums[i];
            overallMax = preMax > overallMax ? preMax : overallMax;    
            if(preMax <= 0) {
                preMax = 0;
            }
        }
        return overallMax;
    }
};