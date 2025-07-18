class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int majEl = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == majEl) {
                count++;
            } else {
                count--;
            }

            if(count < 0) {
                majEl = nums[i];
                count = 1;
            }
        }

        return majEl;
    }
};