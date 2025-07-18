class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long count = 0;
        int ptr1 = 0, ptr2 = 0;
        while(ptr2 < nums.size()) {
            if(nums[ptr2] == 0 && ptr1 == -1) {
                ptr1 = ptr2;
            } else if(nums[ptr2] != 0 && ptr1 != -1) {
                long long n = ptr2 - ptr1;
                count += (n * (n + 1ll)) / 2ll;
                ptr1 = -1;
            }
            ptr2++;
        }
        if(ptr1 != -1) {
            long long n = ptr2 - ptr1;
            count += (n * (n + 1ll)) / 2ll;
        }
        return count;
    }
};