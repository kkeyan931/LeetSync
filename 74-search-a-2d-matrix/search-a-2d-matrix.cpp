class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 1, end = n*m;

        while(start<=end) {
            int mid = (start + end) / 2;

            int row = ceil((double)mid/(double)m) - 1;
            int column = (mid % m) - 1;
            column = column < 0 ? m - 1 : column;

            if(matrix[row][column] == target) return true;

            if(target < matrix[row][column]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};