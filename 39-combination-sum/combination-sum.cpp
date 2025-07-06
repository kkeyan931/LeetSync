class Solution {
public:
    void rec(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums,
             int index, int target) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (target < 0) {
            return;
        }
        if (index == nums.size()) {
            return;
        }

        temp.push_back(nums[index]);
        rec(result, temp, nums, index, target - nums[index]);
        temp.pop_back();
        rec(result, temp, nums, index + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        rec(result, temp, candidates, 0, target);

        return result;
    }
};