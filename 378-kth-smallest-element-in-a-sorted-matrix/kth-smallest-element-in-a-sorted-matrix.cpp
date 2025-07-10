class Solution {
public:
    int count(vector<vector<int>>& matrix, int val) {
        int n = matrix.size();
        int c = 0;

        for (auto& vec : matrix) {
            auto up = upper_bound(vec.begin(), vec.end(), val);
            if (up == vec.end()) {
                c += n;
            } else {
                c += (up - vec.begin());
            }
        }
        return c;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (count(matrix, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};