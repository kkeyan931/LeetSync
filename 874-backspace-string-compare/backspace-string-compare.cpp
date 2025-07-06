class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        int ptr1 = n1 - 1;
        int ptr2 = n2 - 1;

        int hash1 = 0;
        int hash2 = 0;
        while (ptr1 >= 0 || ptr2 >= 0) {

            while (ptr1 >= 0) {
                if (s[ptr1] == '#') {
                    hash1++;
                    ptr1--;
                } else if (hash1 > 0) {
                    ptr1--;
                    hash1--;
                } else {
                    break;
                }
            }

            while (ptr2 >= 0) {
                if (t[ptr2] == '#') {
                    hash2++;
                    ptr2--;
                } else if (hash2 > 0) {
                    ptr2--;
                    hash2--;
                } else {
                    break;
                }
            }

            if (ptr1 >= 0 && ptr2 >= 0 && s[ptr1] != t[ptr2]) {
                return false;
            }
            if ((ptr1 >= 0) != (ptr2 >= 0)) {
                return false;
            }
            ptr1--;
            ptr2--;
        }

        return true;
    }
};