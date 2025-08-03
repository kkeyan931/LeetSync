class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> umap;

        int left = 0;
        int sum = 0;

        int maxi = 0;
        for (int right = 0; right < n; ++right) {

            int rightNum = nums[right];
            umap[rightNum]++;
            sum += rightNum;

            while (umap[rightNum] == 2) {

                int leftNum = nums[left];
                umap[leftNum]--;
                left++;
                sum -= leftNum;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};