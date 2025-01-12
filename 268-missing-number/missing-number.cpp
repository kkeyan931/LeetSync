class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int nSum = (n * (n+1)) / 2;

        long long int sum = accumulate(nums.begin(), nums.end(), 0);

        return nSum - sum;
    }
};