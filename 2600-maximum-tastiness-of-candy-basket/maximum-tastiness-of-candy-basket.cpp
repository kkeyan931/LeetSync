class Solution {
public:
    bool canPick(const vector<int>& price, int k, int minDiff) {
        int last = price[0];
        int count = 1;
        for (int i = 1; i < price.size(); ++i) {
            if (price[i] - last >= minDiff) {
                ++count;
                last = price[i];
            }
            if (count >= k)
                return true;
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        /*
           keyword :: maximize the minimum value -> Binary search on answers
         */
        sort(price.begin(), price.end());
        int lo = 0, hi = price.back() - price.front();
        int answer = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPick(price, k, mid)) {
                answer = mid; // Try to go higher
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return answer;
    }
};
