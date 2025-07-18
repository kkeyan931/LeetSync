class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for(auto str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            umap[s].push_back(str);
        }

        vector<vector<string>> result;
        for(auto [str, vec] : umap) {
            result.push_back(vec);
        }

        return result;
    }
};