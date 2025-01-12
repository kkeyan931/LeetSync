class Solution {
public:
    int getNonZeroIndex(vector<int> &nums, int i) {
        while(i<nums.size()) {
            if(nums[i] != 0) return i;
            i++;
        }
        return -1;
    }
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void moveZeroes(vector<int>& nums) {

     int n = nums.size();
     if(n == 1) return;

     int i = 0;

     while(i<n) {
        if(nums[i] != 0) {
            ++i;
        } else {
            int nonZeroIndex = getNonZeroIndex(nums, i+1);
            if(nonZeroIndex != -1) {
                swap(nums, i, nonZeroIndex);
                ++i;
            } else {
                break;
            }
        }
     }
    }
};