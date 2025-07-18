class Solution {
public:
    bool isPal(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        
        stringstream ss;

        for(auto ch : s) {
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >='0' && ch <='9')) {
                ss << ch;
            }
        }
        string s1 = ss.str();
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        return isPal(s1);
    }
};