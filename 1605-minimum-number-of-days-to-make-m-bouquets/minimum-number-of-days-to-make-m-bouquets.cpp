class Solution {
public:
    int isPossible(vector<int>& bloomDay, int k, int m, int currentDays) {

        int itCount = 0, boq = 0;
        for (auto& daysToGrow : bloomDay) {
            if (daysToGrow <= currentDays) {
                itCount++;
            } else {
                itCount = 0;
            }
            if (itCount == k) {
                boq++;
                itCount = 0;
            }
        }
        return boq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        if ((long long)m * (long long)k > n)
            return -1;

        int maxDayReq = *(max_element(bloomDay.begin(), bloomDay.end()));
        int minDayReq = *(min_element(bloomDay.begin(), bloomDay.end()));
        int start = minDayReq, end = maxDayReq;
        int result = maxDayReq;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            cout << mid << " ";
            if (isPossible(bloomDay, k, m, mid)) {
                result = min(result, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};