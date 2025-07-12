class Solution {
public:
    Solution() { srand(time(0)); }

    int partition(vector<int>& arr, int low, int high) {
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[low], arr[randomIndex]);
        int pivot = arr[low];
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= j && arr[i] >= pivot)
                i++;
            while (i <= j && arr[j] < pivot)
                j--;
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

    int quickSelect(vector<int>& nums, int low, int high, int kIndex) {
        if (low <= high) {
            int pivotIndex = partition(nums, low, high);
            if (pivotIndex == kIndex)
                return nums[pivotIndex];
            else if (pivotIndex > kIndex)
                return quickSelect(nums, low, pivotIndex - 1, kIndex);
            else
                return quickSelect(nums, pivotIndex + 1, high, kIndex);
        }
        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
};
