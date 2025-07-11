class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();

        int ptr1 = 0;
        int ptr2 = 0;

        int mini = INT_MAX;
        int sum = 0;
        while(ptr2 < n) {
            sum += nums[ptr2];

            if(sum >= target) {
                while(sum >= target) {
                    sum = sum - nums[ptr1];
                    ptr1++;
                }
                mini = min(mini, ptr2 - ptr1 + 2);
            }
            ptr2++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};