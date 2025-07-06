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
        
        while(index + 1 < nums.size() && nums[index] == nums[index+1]) {
            index++;
        }

        rec(result, temp, nums, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp;

        rec(result, temp, nums, 0);
        return result;
    }
};