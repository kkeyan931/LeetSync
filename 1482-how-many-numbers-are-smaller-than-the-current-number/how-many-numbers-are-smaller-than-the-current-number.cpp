class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Step 1: Count frequencies for values 0..100
        int freq[101] = {0};
        for (int x : nums) {
            ++freq[x];
        }

        // Step 2: Prefix sums so freq[i] = # of elements <= i
        for (int i = 1; i <= 100; ++i) {
            freq[i] += freq[i - 1];
        }

        // Step 3: For each x, number of strictly smaller elements is:
        // x == 0 ? 0 : freq[x - 1]
        vector<int> ans;
        ans.reserve(nums.size());
        for (int x : nums) {
            ans.push_back(x == 0 ? 0 : freq[x - 1]);
        }
        return ans;
    }
};