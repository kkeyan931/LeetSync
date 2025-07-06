class Solution {
public:
    vector<int> optimal(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        
        result[0]=nums[0];
        for(int i=1;i<n;++i){
            result[i]=result[i-1]*nums[i];
        }
        
        int rpr=1;
        for(int i=n-1;i>0;--i){
            result[i]=result[i-1] * rpr;
            rpr=rpr * nums[i];
        }
        result[0]=rpr;
        
        return result;
    }
    vector<int> naive(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        int zeroCount = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zeroCount++;
            }
        }
        if (zeroCount > 1) {
            return result;
        }
        if (zeroCount == 1) {
            int product = 1;
            int index = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] != 0) {
                    product *= nums[i];
                }
                if (nums[i] == 0) {
                    index = i;
                }
            }
            result[index] = product;
            return result;
        }

        int product = 1;
        for (int i = 0; i < n; ++i) {
            product *= nums[i];
        }
        for (int i = 0; i < n; ++i) {
            result[i] = product / nums[i];
        }
        return result;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        return optimal(nums);
    }
};