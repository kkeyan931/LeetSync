class Solution {
public:
    int rec(string& s, vector<int>& dp, int index) {
        if (index >= s.size()) {
            return 1;
        }
        if (s[index] == '0') {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int one = rec(s, dp, index + 1);
        int two = 0;
        if (index < s.size() - 1) {
            string numStr = std::string(1, s[index]) + s[index + 1];
            int num = stoi(numStr);
            if (num >= 10 && num <= 26) {
                two = rec(s, dp, index + 2);
            }
        }
        return dp[index] = one + two;
    }
    int mem(string& s) {
        vector<int> dp(s.size(), -1);
        return rec(s, dp, 0);
    }
    int table(string& s) {
        if (s[0] == '0') {
            return 0;
        }

        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int one = s[i - 1] - '0';
            int two = stoi(s.substr(i - 2, 2));

            if (1 <= one && one <= 9) {
                dp[i] += dp[i - 1];
            }
            if (10 <= two && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
    int numDecodings(string s) {
        // return mem(s);
        return table(s);
    }
};