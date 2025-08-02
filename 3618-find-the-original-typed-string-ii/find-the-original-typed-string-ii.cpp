class Solution {
    static constexpr int MOD = 1'000'000'007;

    // Convert word into run-lengths: "aabbbc" -> [2,3,1]
    static vector<int> runsOf(const string& s) {
        vector<int> runs;
        int cnt = 1;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == s[i - 1])
                ++cnt;
            else {
                runs.push_back(cnt);
                cnt = 1;
            }
        }
        runs.push_back(cnt);
        return runs;
    }

public:
    int possibleStringCount(string word, int k) {
        vector<int> runs = runsOf(word);
        const int g = (int)runs.size();

        // Product of choices per run (all intended strings without the
        // k-filter)
        long long total = 1;
        for (int r : runs)
            total = (total * r) % MOD;

        // If minimum possible length (pick 1 from each run) is already >= k,
        // everything counts.
        if (k <= g)
            return (int)total; // O(1) early exit.  (Matches known solutions.)
                               // :contentReference[oaicite:4]{index=4}

        // Otherwise, count how many have length < k, then subtract from total.
        // dp[j] = #ways to get exact length j after processing some runs.
        vector<int> dp(k, 0);
        dp[0] = 1; // before any run, length 0 is achievable in 1 way

        int processed = 0;
        for (int r : runs) {
            vector<int> ndp(k, 0);

            // Prefix sums of dp for O(1) range sums:
            // pref[j] = dp[0] + ... + dp[j]
            vector<int> pref(k, 0);
            pref[0] = dp[0];
            for (int j = 1; j < k; ++j) {
                pref[j] = pref[j - 1] + dp[j];
                if (pref[j] >= MOD)
                    pref[j] -= MOD;
            }

            // After using (processed+1) runs, the minimum achievable length is
            // (processed+1). Only fill ndp[j] for j >= processed+1.
            for (int j = processed + 1; j < k; ++j) {
                // newDp[j] = sum_{t=1..min(r, j)} dp[j - t]
                int maxTake = min(r, j);
                int L = j - maxTake; // inclusive
                int R = j - 1;       // inclusive
                int sum = pref[R] - (L > 0 ? pref[L - 1] : 0);
                if (sum < 0)
                    sum += MOD;
                ndp[j] = sum;
            }

            dp.swap(ndp);
            ++processed;
        }

        int invalid = 0; // totals < k
        for (int j = 0; j < k; ++j) {
            invalid += dp[j];
            if (invalid >= MOD)
                invalid -= MOD;
        }

        int ans = (int)((total - invalid) % MOD);
        if (ans < 0)
            ans += MOD;
        return ans;
    }
};
