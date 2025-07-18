class Solution {
public:
    long long sol1(vector<int> &nums) {
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
    long long sol2(vector<int> &nums) {
        long long count = 0;
        int zeroSubarraysEndingAtCurrentIndex = 0;
        
        for(auto num : nums) {
            if(num == 0) {
                count += ++zeroSubarraysEndingAtCurrentIndex;
            } else {
                zeroSubarraysEndingAtCurrentIndex = 0;
            }
        }
        return count;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        // return sol1(nums);
        return sol2(nums);
    }
};