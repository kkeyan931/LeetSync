class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        int n = arr.size();
        
        if(n==1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];


        int start = 0, end = n-1;

        while(start<=end) {
            int mid = start + ((end-start)/2);

            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) {
                return arr[mid];
            }
            if(mid%2==0 && arr[mid]==arr[mid+1] || mid%2!=0 && arr[mid]==arr[mid-1]) {
                start = mid+1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};