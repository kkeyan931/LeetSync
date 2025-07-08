class Solution {
public:
    bool rec(string s, vector<vector<int>>& dp, unordered_set<string>& uset,
             int start, int end) {
        if (end == s.size() && start == end) {
            return true;
        }
        if (end == s.size()) {
            return false;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        string substr = s.substr(start, end - start + 1);
        if (uset.find(substr) != uset.end()) {
            return dp[start][end] = rec(s, dp, uset, end + 1, end + 1) ||
                                    rec(s, dp, uset, start, end + 1);
        }
        return dp[start][end] = rec(s, dp, uset, start, end + 1);
    }
    bool mem(string& s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        return rec(s, dp, uset, 0, 0);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return mem(s, wordDict);
    }
};