class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
            1. try to find the longest prefix that can be a match
            2. swap the break index with the smallest grestest element
            3. reverse the other half
        */

        int n = nums.size();

        int ind = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        if (ind == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        int i = ind + 1;
        int j = n - 1;

        while (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};