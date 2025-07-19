class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> mono;
        for (int i = heights.size() - 1; i >= 0; --i) {
            int h = heights[i], cnt = 0;
            for (; !mono.empty() && mono.top() < h; ++cnt)
                mono.pop();
            heights[i] = cnt + !mono.empty();
            mono.push(h);
        }
        return heights;
    }
};