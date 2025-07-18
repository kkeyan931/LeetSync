class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> umap;

        int pre_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {

            pre_sum += nums[i];

            if (pre_sum % k == 0 && i > 0)
                return true;

            if (umap.find(k - pre_sum % k) != umap.end() &&
                i - umap[k - pre_sum % k] >= 2) {
                return true;
            }

            umap.insert({k - pre_sum % k, i});
        }

        return false;
    }
};