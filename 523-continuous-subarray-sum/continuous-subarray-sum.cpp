class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndex;
        modIndex[0] = -1;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int mod = (sum % k + k) % k;
            if (modIndex.count(mod)) {
                if (i - modIndex[mod] > 1)
                    return true;
            } else {
                modIndex[mod] = i;
            }
        }
        return false;
    }
};