class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();


        // try to find the answer for the smaller array
        if(n>m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int start = 0, end = n;

        int half = ceil((double) (n+m) / (double)2);
        int isEven = (n+m)%2 == 0 ? true : false;
        while(start<=end) {
            int mid = start + ((end-start) / 2);
            
            int l1 = mid-1 >=0 && mid-1 < n ? nums1[mid-1] : INT_MIN;
            int l2 = half-mid-1 >=0 && half-mid-1 < m ? nums2[half-mid-1] : INT_MIN;

            int r1 = mid>=0 && mid<n ? nums1[mid] : INT_MAX;
            int r2 = half-mid>=0 && half-mid < m ? nums2[half-mid] : INT_MAX;


            if(l1<=r2 && l2<=r1) {
                if(isEven)
                 return ((double)max(l1, l2) + (double)min(r1, r2))/(double)2;

                return max(l1, l2);
            }

            if(l2>r1) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return 0;
    }
};