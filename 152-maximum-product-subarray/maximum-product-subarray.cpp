class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int n = nums.size();
        int pre = 1, suf = 1;

        for(int i=0;i<n;++i) {
            if(pre==0) pre=1;
            if(suf==0) suf=1;

            pre=pre*nums[i];
            suf=suf*nums[n-i-1];
            result = max(result, max(pre, suf));
        }
        return result;
    }
};