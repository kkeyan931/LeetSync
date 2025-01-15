class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];

        int count = 1, maxElement = arr[0];

        for(int i=1;i<n;++i) {
            if(maxElement != arr[i]) {
                count--;
            } else {
                count++;
            }
            if(count==0) {
                maxElement = arr[i];
                count=1;
            }
        }
        return maxElement;
    }
};