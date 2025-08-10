class Solution {
public:
    bool dfs(const string& word, unordered_set<string>& wordSet,
             unordered_map<string, bool>& cache) {
        if (cache.find(word) != cache.end()) {
            return cache[word];
        }

        for (int i = 1; i < word.length(); i++) {
            if (wordSet.find(word.substr(0, i)) != wordSet.end()) {
                string suffix = word.substr(i);
                if (wordSet.find(suffix) != wordSet.end() ||
                    dfs(suffix, wordSet, cache)) {
                    cache[word] = true;
                    return true;
                }
            }
        }

        cache[word] = false;
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_map<string, bool> cache;

        for (const string& word : words) {
            if (dfs(word, wordSet, cache)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};