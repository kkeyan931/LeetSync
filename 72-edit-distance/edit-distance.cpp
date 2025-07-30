class Solution {
public:
    int rec(string& word1, string& word2, vector<vector<int>> &dp, int i, int j) {
        if (i < 0) return j + 1; // insert remaining characters of word2
        if (j < 0) return i + 1; // delete remaining characters of word1

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (word1[i] == word2[j]) {
            return rec(word1, word2, dp, i - 1, j - 1);
        }
        int replace = 1 + rec(word1, word2, dp, i - 1, j - 1);
        int del = 1 + rec(word1, word2, dp, i - 1, j);
        int insert = 1 + rec(word1, word2, dp, i, j - 1);

        return dp[i][j] = min({replace, del, insert});
    }
    int mem(string& word1, string& word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return rec(word1, word2, dp, n1 - 1, n2 - 1);
    }
    int minDistance(string word1, string word2) {
        /*
            0. same -> i - 1, j - 1
            1. replace -> i - 1, j - 1
            2. delete -> i - 1, j
            3. insert -> i, j - 1

            max(replace, delete, insert)
        */

        return mem(word1, word2);
    }
};