class Solution {
public:
    bool binarySearch(vector<int> &arr, int target) {

        int n = arr.size();

        int start = 0, end = n-1;

        while(start<=end) {
            int mid = (start+end) / 2;

            if(arr[mid] == target) return true;

            if(arr[mid]>target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
    bool useBinarySearch(vector<vector<int>>& matrix, int target) {
        int noOfRows = matrix.size();
        int noOfColumns = matrix[0].size();

        for(int row=0; row<noOfRows; ++row) {
            if(matrix[row][0]<=target && matrix[row][noOfColumns -1]>=target) {
                if(binarySearch(matrix[row], target)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool traverseAndEliminate(vector<vector<int>>& matrix, int target) {

        int noOfRows = matrix.size();
        int noOfColumns = matrix[0].size();

        int row = 0, column = noOfColumns - 1;

        while(row<noOfRows && column>=0) {
            int element = matrix[row][column];

            if(element == target) {
                return true;
            }

            if(matrix[row][column] > target) {
                column--;
            } else { 
                row++;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return useBinarySearch(matrix, target);

        return traverseAndEliminate(matrix, target);
    }
};