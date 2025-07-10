class Solution {
public:
    // similar to Dijkstra algorithm
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        vector<vector<int>> result;

        set<pair<int, int>> uset;

        pq.push({nums1[0] + nums2[0], 0, 0});
        uset.insert({0, 0});

        while (!pq.empty() && k--) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < n2 && uset.find({i, j + 1}) == uset.end()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
                uset.insert({i, j + 1});
            }
            if (i + 1 < n1 && uset.find({i + 1, j}) == uset.end()) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                uset.insert({i + 1, j});
            }
        }
        return result;
    }
};