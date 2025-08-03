class Solution {
public:
    vector<int> computeLPS(string s) {
        int n = s.size();

        vector<int> LPS(n, 0);

        int i = 1;
        int j = 0;

        while (i < n) {
            if (s[i] == s[j]) {
                LPS[i] = j + 1;
                j++;
                i++;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = LPS[j - 1];
                }

                if (s[i] == s[j]) {
                    LPS[i] = j + 1;
                    j++;
                }
                i++;
            }
        }
        return LPS;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps = computeLPS(s);

        int p = lps[n - 1];

        return p > 0 && n % (n - p) == 0;
    }
};