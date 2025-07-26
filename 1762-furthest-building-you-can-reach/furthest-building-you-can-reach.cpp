class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        /*
        1. Be greedy and use ladders for each gap, but also maintain a priority
        queue for each gap.
        2. When you run out of ladders, try to see if the smallest used ladder
        is smaller than current gap; this way you switch them and replace the
        smallest one with bricks.
        3. If out of ladders, unable to swap and repalce with bricks, stop
        there.
        */
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = heights.size();
        int i = 0;

        for (int i = 0; i < n - 1; ++i) {
            int climb = heights[i + 1] - heights[i];

            if (climb <= 0) {
                continue;
            }

            pq.push(climb);

            if (pq.size() <= ladders) {
                continue;
            }
            int top = pq.top();
            pq.pop();
            bricks = bricks - top;

            if (bricks < 0) {
                return i;
            }
        }
        return n - 1;
    }
};