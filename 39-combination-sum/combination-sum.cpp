class Solution {
public:
    void combinationBuilder(vector<int>& candidates,
                            vector<vector<int>>& result, vector<int>& builder,
                            int index, int target) {

        if (target == 0) {
            result.push_back(builder);
            return;
        }

        if (index >= candidates.size()) {
            return;
        }

        if (target - candidates[index] >= 0) {
            builder.push_back(candidates[index]);
            combinationBuilder(candidates, result, builder, index,
                               target - candidates[index]);
            builder.pop_back();
        }
        combinationBuilder(candidates, result, builder, index + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> builder;

        combinationBuilder(candidates, result, builder, 0, target);

        return result;
    }
};