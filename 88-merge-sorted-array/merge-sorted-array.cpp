class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int ptr1 = m - 1;
        int ptr2 = n - 1;

        int k = (m + n) - 1;

        while (ptr1 >= 0 && ptr2 >= 0) {
            if (nums1[ptr1] > nums2[ptr2]) {
                nums1[k] = nums1[ptr1];
                ptr1--;
            } else {
                nums1[k] = nums2[ptr2];
                ptr2--;
            }
            k--;
        }

        while (ptr1 >= 0) {
            nums1[k] = nums1[ptr1];
            ptr1--;
            k--;
        }

        while (ptr2 >= 0) {
            nums1[k] = nums2[ptr2];
            ptr2--;
            k--;
        }
    }
};