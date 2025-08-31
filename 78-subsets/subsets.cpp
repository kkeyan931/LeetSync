class Solution {
public:
    void subsetBuilder(vector<int>& nums, vector<vector<int>>& result,
                       vector<int>& builder, int index) {

        if (index == nums.size()) {
            result.push_back(builder);
            return;
        }

        // include
        builder.push_back(nums[index]);
        subsetBuilder(nums, result, builder, index + 1);

        // exclude
        builder.pop_back();
        subsetBuilder(nums, result, builder, index + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> builder;

        subsetBuilder(nums, result, builder, 0);

        return result;
    }
};