class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        if(n1 > n2) {
            return false;
        }

        int ptr1 = 0;
        int ptr2 = 0;

        while(ptr1 < n1 && ptr2 < n2) {
            if(s[ptr1] == t[ptr2]) {
                ptr1++;
                ptr2++;
            } else {
                ptr2++;
            }
        }

        if(ptr1 == n1) {
            return true;
        }
        return false;
    }
};