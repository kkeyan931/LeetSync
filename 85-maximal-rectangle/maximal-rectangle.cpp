class Solution {
public:
    vector<int> NSE(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> nse(arr.size());
        stack<int> st;

        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> PSE(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int leetcode84(vector<int>& input) {
        vector<int> nse = NSE(input);
        vector<int> pse = PSE(input);

        int maxi = 0;
        for (int i = 0; i < input.size(); ++i) {
            int size = input[i] * (nse[i] - pse[i] - 1);

            maxi = max(maxi, abs(size));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> arr(m, 0);

        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    arr[j] = arr[j] + 1;
                } else {
                    arr[j] = 0;
                }
            }
            maxi = max(maxi, leetcode84(arr));
        }
        return maxi;
    }
};