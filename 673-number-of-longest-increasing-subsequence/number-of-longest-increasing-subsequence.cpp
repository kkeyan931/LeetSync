class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> lis(n, 1);
        vector<int> counter(n, 1);
        int maxi = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    if(lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        counter[i] = counter[j];
                        maxi = max(maxi, lis[i]);
                    } else if(lis[j] + 1 == lis[i]) {
                        counter[i] += counter[j];
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(lis[i] == maxi) {
                count += counter[i];
            }
        }
        return count;
    }
};