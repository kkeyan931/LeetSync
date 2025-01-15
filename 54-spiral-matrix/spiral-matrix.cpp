class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0, bottom = n-1;
        int left = 0, right = m-1;

        vector<int> result(n*m);
        int index=0;
        while(left<=right && top<=bottom) {
            for(int i=left;i<=right;++i) {
                result[index++] = matrix[top][i];
            }
            top++;
            for(int i=top;i<=bottom;++i) {
                result[index++] = matrix[i][right];
            }
            right--;
            
            if(top<=bottom) {
                for(int i=right;i>=left;--i) {
                    result[index++] = matrix[bottom][i];
                }
                bottom--;
            }
            if(left<=right) {
                for(int i=bottom;i>=top;--i) {
                    result[index++] = matrix[i][left];
                }
                left++;
            }
        }

        return result;
    }
};