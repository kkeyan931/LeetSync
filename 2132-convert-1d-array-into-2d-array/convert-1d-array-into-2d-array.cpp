class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();

        if(m * n != size) {
            return {};
        }
        
        vector<vector<int>> result(m, vector<int>(n));
        
        int index = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                result[i][j] = original[index++];
            }
        }
        return result;
    }
};