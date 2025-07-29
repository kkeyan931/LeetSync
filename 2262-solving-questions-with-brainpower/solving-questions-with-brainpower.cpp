class Solution {
public:
    long long rec(vector<vector<int>>& questions, vector<long long> &dp, int index) {
        if(index >= questions.size()) {
            return 0;
        }

        if(dp[index] != -1) {
            return dp[index];
        }
        
        long long take = rec(questions, dp, index + questions[index][1] + 1) + (long long)questions[index][0];
        long long notTake = rec(questions, dp, index + 1);

        return dp[index] = max(take, notTake);
    }
    long long mem(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return rec(questions, dp, 0);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return mem(questions);
    }
};