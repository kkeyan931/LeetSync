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
    bool mem1(string& s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        return rec(s, dp, uset, 0, 0);
    }
    bool rec2(const string& s, const vector<string>& wordDict, int idx, vector<int>& memo) {
        if (idx == s.size()) return true;
        if (memo[idx] != -1) return memo[idx];
        for (int i = 0, n = wordDict.size(); i < n; ++i) {
            int len = wordDict[i].size();
            if (idx + len <= s.size() && s.compare(idx, len, wordDict[i]) == 0) {
                if (rec2(s, wordDict, idx + len, memo)) return memo[idx] = true;
            }
        }
        return memo[idx] = false;
    }

    bool mem2(string& s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return rec2(s, wordDict, 0, memo);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // return mem(s, wordDict);
        return mem2(s, wordDict);
    }
};