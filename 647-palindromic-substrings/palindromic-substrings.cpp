class Solution {
public:
    int n;
    vector<vector<int>> dp;

    // Memoized palindrome checker
    bool isPal(string& s, int i, int j) {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] != s[j])
            return dp[i][j] = false;
        return dp[i][j] = isPal(s, i + 1, j - 1);
    }

    // Explore all substrings recursively
    int countPalindromes(string& s, int start, int end) {
        if (start == n)
            return 0;
        if (end == n)
            return countPalindromes(s, start + 1, start + 1);

        int count = isPal(s, start, end) ? 1 : 0;
        return count + countPalindromes(s, start, end + 1);
    }

    int countSubstrings(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1)); // Memo table for palindrome check
        return countPalindromes(s, 0, 0);
    }
};
