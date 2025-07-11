class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a,
                                             vector<vector<int>>& b) {
        int n1 = a.size();
        int n2 = b.size();

        if(n1 == 0 || n2 == 0) {
            return {};
        } 

        vector<vector<int>> result;
        int i = 0, j = 0;

        while(i < n1 && j < n2) {
            if(a[i][1] >= b[j][0] && a[i][0] <= b[j][1]) {
                result.push_back({max(a[i][0], b[j][0]), min(a[i][1], b[j][1])});
            }
            if(a[i][1] > b[j][1]) {
                j++;
            } else {
                i++;
            }
        }
        return result;
    }
};