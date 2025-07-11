class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end());

        vector<pair<int, int>> result;

        for (auto& point : points) {
            if (!result.empty() && result.back().second >= point[0]) {
                result.back().second =
                    min(max(result.back().second, point[0]), point[1]);
            } else {
                result.push_back({point[0], point[1]});
            }
        }
        return result.size();
    }
};