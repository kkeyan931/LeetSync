class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxDay = 0;

        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        
        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());
        int ans = 0;
        for (int day = 0, j = 0; day <= maxDay; day++) {

            /* get all the events that can be attended on day i */
            while (j < n && events[j][0] <= day) {
                pq.emplace(events[j][1]);
                j++;
            }

            /* remove expired events*/
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};