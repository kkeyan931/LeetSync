class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {

        int m = arr.size();
        int n = arr[0].size();

        vector<int> result(m * n);
        int index = 0;

        int direction = 0;

        int top = 0;
        int left = 0;
        int down = m - 1;
        int right = n - 1;

        while (top <= down && left <= right) {

            if (direction == 0) {
                for (int i = left; i <= right; ++i) {
                    result[index++] = arr[top][i];
                }
                top++;
            }
            if (direction == 1) {
                for (int i = top; i <= down; i++) {
                    result[index++] = arr[i][right];
                }
                right--;
            }
            if (direction == 2) {
                for (int i = right; i >= left; i--) {
                    result[index++] = arr[down][i];
                }
                down--;
            }
            if (direction == 3) {
                for (int i = down; i >= top; i--) {
                    result[index++] = arr[i][left];
                }
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return result;
    }
};