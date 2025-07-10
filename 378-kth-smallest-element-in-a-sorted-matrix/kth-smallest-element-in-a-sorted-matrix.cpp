class Solution {
public:
    int count(vector<vector<int>>& matrix, int val) {

        int n = matrix.size();
        int i = 0;
        int j = n - 1;

        int count = 0;

        while (i < n && j >= 0) {

            if (matrix[i][j] <= val) {
                count += j + 1;
                i++;
            }

            else {
                j--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        // int m=matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (count(matrix, mid) < k) {
                low = mid + 1;
            }

            else {
                high = mid;
            }
        }

        return low;
    }
};