class Solution {
public:
    void rec(vector<vector<int>> &result, vector<int> &temp, vector<int> &nums, int index) {

        if(index == nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        rec(result, temp, nums, index+1);
        temp.pop_back();
        for(int i = index + 1 ; i < nums.size(); ++i) {
            if(nums[index] != nums[i]) {
                return rec(result, temp, nums, i);
            }
        }
        rec(result, temp, nums, nums.size());
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp;

        rec(result, temp, nums, 0);
        return result;
    }
};