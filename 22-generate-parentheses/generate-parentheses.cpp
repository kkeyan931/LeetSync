class Solution {
public:
    void rec(vector<string> &result, string temp, int open, int close, int n) {
        if(open + close == 2 * n) {
            result.push_back(temp);
            return;
        }
        if(open < n) {
            rec(result, temp + "(", open + 1, close, n);
        }
        if(close < open) {
            rec(result, temp + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        rec(result, "", 0, 0, n);

        return result;
    }
};