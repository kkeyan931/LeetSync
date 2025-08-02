class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        /*  
            1. find the NSE two times
            2. Having the circular queue is nothing but traversing the array two times
        */

        stack<int> mstack;

        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!mstack.empty() && arr[mstack.top()] <= arr[i]) {
                mstack.pop();
            }
            mstack.push(i);
        }
        vector<int> result(arr.size());
        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!mstack.empty() && arr[mstack.top()] <= arr[i]) {
                mstack.pop();
            }
            if (mstack.empty()) {
                result[i] = -1;
            } else {
                result[i] = arr[mstack.top()];
            }
            mstack.push(i);
        }
        return result;
    }
};