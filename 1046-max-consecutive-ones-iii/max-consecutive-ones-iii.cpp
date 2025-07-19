class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ptr1 = 0;
        int ptr2 = 0;

        int totalK = k;

        int maxi = 0;
        while(ptr2 < n) {
            if(nums[ptr2] == 0) {
                k--;
            }
            while(k < 0 && ptr1 <= ptr2) {
                if(nums[ptr1] == 0) {
                    k++;
                }
                ptr1++;
            }
            maxi = max(maxi, ptr2 - ptr1 + 1);
            ptr2++;
        }

        return maxi;
    }
};