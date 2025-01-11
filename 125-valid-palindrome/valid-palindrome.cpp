class Solution {
public:
    char toLowerCase(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + ('a' - 'A');
        }
        return ch;
    }
    string pre(string s) {
        string str = "";
        for(int i=0;i<s.size();++i) {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) str += toLowerCase(s[i]);
            if(s[i]>='0' && s[i]<='9') str+=s[i];
        }
        return str;
    }

    bool rec(string &s, int start, int end) {
        if(start>=end) return true;

        if(s[start] != s[end]) return false;
        return rec(s, start+1, end-1);
    }
    bool isPalindrome(string s) {
        s = pre(s);
        // memory limit reached
        return rec(s, 0, s.size()-1);
    }
};