class Solution {
public:
    void reverse(string &s, int i, int j) {
        while(i <= j) {
            swap(s[i++], s[j--]);
        }
    }
    string reverseWords(string s) {
        string str;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ' && (str.empty() || str.back() == ' ')) continue;
            str += s[i];
        }
        if(str[str.size() - 1] == ' ') {
            str.pop_back();
        }
        reverse(str, 0, str.size() - 1);

        int prev = -1;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == ' ') {
                reverse(str, prev + 1, i - 1);
                prev = i;
            }
        }
        reverse(str, prev + 1, str.size() - 1);
        return str;
    }
};