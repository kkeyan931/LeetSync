class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<int, vector<int>> umap;

        for(int i = 0; i < s.size(); ++i) {
            umap[s[i]].push_back(i);
        }

        int count = 0;
        for(auto &word : words) {
            int latest = -1;
            for(int i = 0; i < word.size(); ++i) {
                auto it = upper_bound(umap[word[i]].begin(), umap[word[i]].end(), latest);

                if(it == umap[word[i]].end()) break;
                
                latest = *it;

                if(i == word.size() - 1) count++;
            }
        }
        return count;
    }
};