class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int majEl = nums[0];
        int count = 1;
        for(int i = 1; i < n; ++i) {
            if(majEl == nums[i]) {
                count++;
            } else {
                count--;
            }
            if(count == 0) {
                majEl = nums[i];
                count = 1;
            }
        }
        return majEl;
    }
};