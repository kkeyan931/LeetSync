class Solution {
public:
    string rec(string& s1, string& s2, int i, int j,
               vector<vector<string>>& dp) {

        if (i < 0)
            return s2.substr(0, j + 1);
        if (j < 0)
            return s1.substr(0, i + 1);

        if (!dp[i][j].empty())
            return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = rec(s1, s2, i - 1, j - 1, dp) + s1[i];
        } else {
            string opt1 = rec(s1, s2, i - 1, j, dp) + s1[i];
            string opt2 = rec(s1, s2, i, j - 1, dp) + s2[j];

            dp[i][j] = (opt1.size() < opt2.size()) ? opt1 : opt2;
        }

        return dp[i][j];
    }

    string mem(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<string>> dp(m, vector<string>(n, ""));
        return rec(s1, s2, m - 1, n - 1, dp);
    }
    string table(string& str1, string& str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {

                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n, j = m;

        string result;
        while (i > 0 && j > 0) {

            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            result += str1[i - 1];
            i--;
        }

        while (j > 0) {
            result += str2[j - 1];
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        // return mem(str1, str2);
        return table(str1, str2);
    }
};