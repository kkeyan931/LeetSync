class Solution {
public:
    void rec(vector<string> &result, string &s, int index) {
        if(index == s.size()) {
            result.push_back(s);
            return;
        }
        if(s[index] >= '0' && s[index] <= '9') {
            return rec(result, s, index+1);
        }
        rec(result, s, index+1);
        char ch = s[index];
        
        if(ch >= 'A' && ch <= 'Z') {
            s[index] = tolower(s[index]);
        } else {
            s[index] = toupper(s[index]);
        }
        rec(result, s, index+1);

        s[index] = ch;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        rec(result, s, 0);
        return result;
    }
};