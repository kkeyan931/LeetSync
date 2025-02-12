class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0, end = (n*m) -1;

        while(start<=end) {
            int mid = (start + end) / 2;

            int row = mid/m;
            int column = mid % m;

            if(matrix[row][column] == target) return true;

            if(target < matrix[row][column]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }

    bool travarseAndEliminate(vector<vector<int>>& matrix, int target) {
        int noOfRows = matrix.size(); // row
        int noOfColumns = matrix[0].size(); // column

        int row = 0, column = noOfColumns-1;

        while(row < noOfRows && column >= 0) {
            if(matrix[row][column] == target) return true;
            
            if(target < matrix[row][column]) {
                column--;
            } else {
                row++;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix, target);
        // return travarseAndEliminate(matrix, target);
    }
};