class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string ans;
        vector<string> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = to_string(nums[i]);
        sort(res.begin(), res.end(),
             [](const string& a, const string& b) { return a + b > b + a; });
        if (res[0] == "0")
            return "0";
        for (int i = 0; i < n; ++i)
            ans += res[i];
        return ans;
    }
};