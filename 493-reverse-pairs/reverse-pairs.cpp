class Solution {
public:
    
    int countPairs(vector<int> &nums, int low, int mid, int high) {
        int ptr2 = mid+1;
        int count = 0;
        for(int ptr1=low;ptr1<=mid;++ptr1) {
            while(ptr2<=high && nums[ptr1] > 2 * (long) nums[ptr2]) {
                ptr2++;
            }
            count += (ptr2 - (mid+1));
        }
        return count;
    }
    int mergeSort(vector<int> &nums, int low, int high) {
        int count = 0;
        if(low>=high) return count;
        int mid = low + ((high-low)/2);
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp;
        int ptr1 = low, ptr2 = mid+1;

        while(ptr1<=mid && ptr2<=high) {
            if(nums[ptr1]<nums[ptr2]) {
                temp.push_back(nums[ptr1++]);
            } else {
                temp.push_back(nums[ptr2++]);
            }
        }
        while(ptr1<=mid) temp.push_back(nums[ptr1++]);
        while(ptr2<=high) temp.push_back(nums[ptr2++]);

        for(int i=low;i<=high;++i) nums[i]=temp[i-low];
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};