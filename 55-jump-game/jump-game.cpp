class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};