class Solution {
public:
    void build(int n, int k, vector<vector<int>>& result, vector<int>& builder,
               int start) {

        if (builder.size() == k) {
            result.push_back(builder);
            return;
        }

        for (int number = start; number <= n; ++number) {
            builder.push_back(number);
            build(n, k, result, builder, number + 1);
            builder.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> builder;

        build(n, k, result, builder, 1);

        return result;
    }
};