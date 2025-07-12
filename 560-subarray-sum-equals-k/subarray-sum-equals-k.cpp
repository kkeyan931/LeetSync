class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        int sum = 0;
        int count = 0;
        for (auto num : nums) {
            sum += num;

            if (sum == k) {
                count++;
            }
            int remaining = sum - k;

            if (map.find(remaining) != map.end()) {
                count += map[remaining];
            }
            map[sum]++;
        }
        return count;
    }
};