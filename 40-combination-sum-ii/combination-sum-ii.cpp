class Solution {
public:

    void rec(vector<vector<int>> &result, vector<int> &temp, vector<int> &nums, int index, int target) {
        
        if(target == 0) {
            result.push_back(temp);
            return;
        }
        if(target < 0) {
            return;
        }
        if(index == nums.size()) {
            return;
        }
        temp.push_back(nums[index]);
        rec(result, temp, nums, index + 1, target - nums[index]);
        temp.pop_back();

        while(index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        rec(result, temp, nums, index + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        rec(result, temp, candidates, 0, target);

        return result;
    }
};