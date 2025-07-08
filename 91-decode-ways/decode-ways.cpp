class Solution {
public:
    int rec(string &s, vector<int> &dp, int index) {
        if(index >= s.size()) {
            return 1;
        }
        if(s[index] == '0') {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int one = rec(s, dp, index+1);
        int two = 0;
        if(index < s.size() - 1) {
            string numStr = std::string(1, s[index]) + s[index+1];
            int num = stoi(numStr);
            if(num >= 10 && num <= 26) {
                two = rec(s, dp, index + 2);
            }
        }
        return dp[index] = one + two;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return rec(s, dp, 0);
    }
};