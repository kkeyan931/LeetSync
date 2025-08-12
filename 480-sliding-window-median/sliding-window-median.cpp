class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        multiset<double> mset(nums.begin(), nums.begin() + k);

        auto mid = next(mset.begin(), k / 2);

        vector<double> result;

        for (int i = k; i <= nums.size(); ++i) {

            double median = (double)(*mid + *prev(mid, 1 - k % 2)) / (double)2;

            result.push_back(median);

            if (i == nums.size())
                return result;

            mset.insert(nums[i]);

            if (nums[i] < *mid)
                mid--;

            if (nums[i - k] <= *mid)
                mid++;

            mset.erase(mset.lower_bound(nums[i - k]));
        }

        return result;
    }
};