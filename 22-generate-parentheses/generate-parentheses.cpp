class Solution {
public:
    void build(vector<string>& result, string builder, int n, int open,
               int close) {

        if (open + close == 2 * n) {
            result.push_back(builder);
            return;
        }
        if (open < n) {
            build(result, builder + "(", n, open + 1, close);
        }
        if (close < open) {
            build(result, builder + ")", n, open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        build(result, "", n, 0, 0);

        return result;
    }
};