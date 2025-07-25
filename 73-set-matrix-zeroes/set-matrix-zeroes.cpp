class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0) {
                        firstRowZero = true;
                    }
                    if(j == 0) {
                        firstColZero = true;
                    }
                }
            }
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
                if(matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(firstRowZero) {
                matrix[0][i] = 0;
            }
        }
        
        for(int i = 0; i < m; ++i) {
            if(firstColZero) {
                matrix[i][0] = 0;
            }
        }
    }
};