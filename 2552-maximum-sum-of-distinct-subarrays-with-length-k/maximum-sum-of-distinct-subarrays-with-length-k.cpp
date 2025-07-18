class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long sum = 0;
        unordered_map<int, int> umap;
        for(int i = 0; i < k; ++i) {
            umap[nums[i]]++;
            sum += nums[i];
        }
        long long maxi = 0;
        if(umap.size() == k) {
            maxi = sum;
        }

        for(int i = k; i < nums.size(); ++i) {
            
            umap[nums[i-k]]--;
            sum -= nums[i-k];
            if(umap[nums[i-k]] == 0) {
                umap.erase(nums[i-k]);
            }
            umap[nums[i]]++;
            sum += nums[i];

            if(umap.size() == k) {
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};