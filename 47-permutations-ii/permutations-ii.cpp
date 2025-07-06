class Solution {
public:
    void rec(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums,
             vector<bool>& visited) {

        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {

            if(i > 0 && nums[i] == nums[i-1] && visited[i-1] == false) continue;

            if(visited[i] == false) {

                visited[i] = true;
                temp.push_back(nums[i]);

                rec(result, temp, nums, visited);

                visited[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        rec(result, temp, nums, visited);

        return result;
    }
};