/*
  Core idea:
    - Build gaps array g of size n+1.
    - Answer = max sum of any (k+1) consecutive gaps.
    - If k+1 > g.size(), clamp window size to g.size().
*/
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = (int)startTime.size();
        if (n == 0)
            return eventTime; // no meetings: whole event is free


        // Build gaps: g[0] = start[0] - 0; g[i] = start[i] - end[i-1]; g[n] =
        // eventTime - end[n-1].
        vector<long long> g;
        g.reserve(n + 1);

        g.push_back(max(0, startTime[0] - 0));
        for (int i = 1; i < n; ++i) {
            g.push_back(max(0, startTime[i] - endTime[i - 1]));
        }
        g.push_back(max(0, eventTime - endTime[n - 1]));

        // Window size is k+1 (merging k+1 consecutive gaps by moving k
        // meetings).
        int w = min<int>(k + 1, (int)g.size());
        if (w <= 0)
            return 0; // degenerate (shouldn't happen)

        // Sliding window to find max sum over any w consecutive gaps.
        long long win = 0;
        for (int i = 0; i < w; ++i)
            win += g[i];
        long long ans = win;

        for (int r = w; r < (int)g.size(); ++r) {
            win += g[r] - g[r - w];
            ans = max(ans, win);
        }

        return (int)ans;
    }
};
