class Solution {
public:
    void rec(vector<string>& result, unordered_map<char, string>& umap,
             string& temp, string& digits, int index) {

        if (temp.size() == digits.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i < digits.size(); ++i) {
            for (auto ch : umap[digits[i]]) {
                temp.push_back(ch);
                rec(result, umap, temp, digits, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        unordered_map<char, string> umap = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> result;
        string temp;
        rec(result, umap, temp, digits, 0);
        return result;
    }
};