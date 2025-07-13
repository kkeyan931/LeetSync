class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        /*
            1. Break the problem into small problem (only two list)
            2. Find a solution for the small problem (two pointers)
            3. Apply the learning to the large problem (multi pointers)
            4. optimize the solution (priority_queue)
        */

        int n = nums.size();

        vector<int> pointers(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> result(2);

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i][0], i});
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
        }
        result[0] = mini;
        result[1] = maxi;

        while (pq.size() == n) {
            auto [_, index] = pq.top();
            pq.pop();

            pointers[index]++;

            if (pointers[index] == nums[index].size())
                break;

            int next = nums[index][pointers[index]];

            pq.push({next, index});

            mini = pq.top().first;
            maxi = max(next, maxi);

            if (maxi - mini < result[1] - result[0]) {
                result[0] = mini;
                result[1] = maxi;
            }
        }
        return result;
    }
};