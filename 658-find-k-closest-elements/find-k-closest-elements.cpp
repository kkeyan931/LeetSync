class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        auto lb = lower_bound(arr.begin(), arr.end(), x);

        if (lb == arr.begin()) {
            vector<int> result(k);
            int index = 0;
            for (int i = 0; i < k; ++i) {
                result[index++] = arr[i];
            }
            return result;
        }
        if (lb == arr.end()) {
            vector<int> result(k);
            int index = k;
            for (int i = n - 1; i >= n - k; i--) {
                result[--index] = arr[i];
            }
            return result;
        }
        vector<int> result;

        int lb_index = lb - arr.begin();
        if(abs(arr[lb_index - 1] - x) <= abs(arr[lb_index] - x)) {
            lb_index = lb_index - 1;
        }

        result.push_back(arr[lb_index]);
        

        int ptr1 = lb_index - 1;
        int ptr2 = lb_index + 1;

        while (ptr1 >= 0 && ptr2 < n && result.size() != k) {
            if (abs(arr[ptr1] - x) <= abs(arr[ptr2] - x)) {
                result.push_back(arr[ptr1--]);
            } else {
                result.push_back(arr[ptr2++]);
            }
        }
        while (ptr1 >= 0 && result.size() != k) {
            result.push_back(arr[ptr1--]);
        }
        while (ptr2 < n && result.size() != k) {
            result.push_back(arr[ptr2++]);
        }

        sort(result.begin(), result.end());
        return result;
    }
};