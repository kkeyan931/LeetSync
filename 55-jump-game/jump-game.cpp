class Solution {
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;

        int maxReach = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (i > maxReach)
                return false;
            maxReach = max(maxReach, nums[i] + i);
            if (maxReach >= n - 1)
                return true;
        }
        return true;
    }
};