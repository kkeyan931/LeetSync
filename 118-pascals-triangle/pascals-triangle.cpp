class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> result;
        
        result.push_back({1});
        
        int i = 1;
        while(i<numRows) {
            vector<int> innerVec(i+1);

            for(int j=0;j<=i;++j) {
                if(j==0 || j==i) {
                    innerVec[j] = 1;
                } else {
                    innerVec[j] = result[i-1][j-1] + result[i-1][j];
                }
            }
            result.push_back(innerVec);
            i++;
        }
        return result;
    }
};