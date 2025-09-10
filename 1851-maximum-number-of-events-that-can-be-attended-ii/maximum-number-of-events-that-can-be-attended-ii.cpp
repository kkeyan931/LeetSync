class Solution {
public:
    int getNextIndex(vector<vector<int>>& events, int target) {
        int low = 0;
        int high = events.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (target >= events[mid][0]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    int rec(vector<vector<int>>& events, vector<vector<int>>& dp, int index,
            int k) {
        if (index == events.size()) {
            return 0;
        }
        if (k == 0) {
            return 0;
        }
        if (dp[index][k] != -1) {
            return dp[index][k];
        }

        int pick =
            events[index][2] +
            rec(events, dp, getNextIndex(events, events[index][1]), k - 1);
        int notPick = rec(events, dp, index + 1, k);

        return dp[index][k] = max(pick, notPick);
    }
    int mem(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return rec(events, dp, 0, k);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        /*
            1. sort based on the start time.
            2. use pick or not pick DP
            3. use binary-search to get the next index
        */
        return mem(events, k);
    }
};