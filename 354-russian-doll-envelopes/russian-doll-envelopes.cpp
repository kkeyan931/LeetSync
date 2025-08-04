class Solution {
public:
    int twoD(vector<vector<int>>& env) {
        sort(env.begin(), env.end());

        int n = env.size();
        vector<int> dp(n, 1);

        int mx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (env[i][0] > env[j][0] && env[i][1] > env[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }
    struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                /* decreasing in the second dimension */
                return a[1] > b[1];
            }
            /* incresing in the first dimension */
            return a[0] < b[0];
        }
    };
    int upperBound(vector<int> &lis, vector<int>& env) {

        int n = lis.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (lis[mid] >= env[1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int binarySearch(vector<vector<int>>& envelopes) {

        int n = envelopes.size();

        /* important sort */
        sort(envelopes.begin(), envelopes.end(), comp{});

        vector<int> lis;

        for (auto env : envelopes) {
            int i = upperBound(lis, env);
            if (i == lis.size()) {
                lis.push_back(env[1]);
            } else {
                lis[i] = env[1];
            }
        }
        return lis.size();
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        // return twoD(env);
        return binarySearch(env);
    }
};