class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int> &temp,
                vector<int>& nums, vector<bool>& visited) {

        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int index = 0; index < nums.size(); index++) {
            if (visited[index] == false) {
                temp.push_back(nums[index]);
                visited[index] = true;
                helper(result, temp, nums, visited);
                visited[index] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        helper(result, temp, nums, visited);

        return result;
    }
};