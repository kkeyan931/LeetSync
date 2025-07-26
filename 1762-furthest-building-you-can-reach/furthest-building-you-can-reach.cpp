class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int, vector<int>, greater<int>> pq;

        int n = heights.size();
        int i = 0;
        while (i < n - 1) {
            if (heights[i + 1] <= heights[i]) {
                i++;
                continue;
            }
            if (ladders > 0) {
                ladders--;
                pq.push(heights[i + 1] - heights[i]);
                i++;
                continue;
            }
            int gap = heights[i + 1] - heights[i];
            if (!pq.empty()) {
                int top = pq.top();

                if (gap > top && bricks >= top) {
                    bricks = bricks - top;
                    pq.pop();
                    pq.push(gap);
                    i++;
                    continue;
                }
            }
            if (gap <= bricks) {
                bricks = bricks - gap;
                i++;
                continue;
            }
            return i;
        }
        return i;
    }
};