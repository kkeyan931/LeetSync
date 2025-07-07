class Solution {
public:
    int bestL = 0, bestR = 0;
    void extend(const string& s, int L, int R) {
        int n = s.size();
        while (L >= 0 && R < n && s[L] == s[R]) {
            --L;
            ++R;
        }
        ++L;
        --R;
        if (R - L > bestR - bestL) {
            bestL = L;
            bestR = R;
        }
    }

    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            extend(s, i, i);     // Odd length
            extend(s, i, i + 1); // Even length
        }
        return s.substr(bestL, bestR - bestL + 1);
    }
};