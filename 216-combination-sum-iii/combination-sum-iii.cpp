class Solution {
public:
    void rec(vector<vector<int>> &result, vector<int> &temp, int index, int k, int n, int sum) {
        if(temp.size() == k && sum == n) {
            result.push_back(temp);
            return;
        }
        if(temp.size() > k || sum > n) {
            return;
        }

        for(int i = index; i <= 9; ++i) {
            temp.push_back(i);
            rec(result, temp, i + 1, k, n, sum + i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        rec(result, temp, 1, k, n, 0);

        return result;
    }
};