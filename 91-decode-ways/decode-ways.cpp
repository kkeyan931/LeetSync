class Solution {
public:
    int rec(string& s, vector<int> &dp, int index) {

        if (index == s.size()) {
            return 1;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        int count = 0;
        if (index < s.size()) {
            char str = s[index];
            if (str >= '1' && str <= '9') {
                count += rec(s, dp, index + 1);
            }
        }
        if (index + 1 < s.size()) {
            string str = s.substr(index, 2);

            if (s[0] != '0' && stoi(str) >= 10 && stoi(str) <= 26) {
                count += rec(s, dp, index + 2);
            }
        }
        return dp[index] = count;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return rec(s, dp, 0); 
    }
};