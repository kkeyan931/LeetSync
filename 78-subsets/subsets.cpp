class Solution {
public:
    void rec(vector<int> &nums, vector<vector<int>> &result, vector<int> &temp, int index) {
        if(index == nums.size()) {
            result.push_back(temp);
            return;
        }
        rec(nums, result, temp, index+1);
        temp.push_back(nums[index]);
        rec(nums, result, temp, index+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        
        rec(nums, result, temp, 0);

        return result;
    }
};