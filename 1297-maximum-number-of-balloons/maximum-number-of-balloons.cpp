class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> umap;

        for (auto ch : text) {
            umap[ch]++;
        }
        int count = 0;
        while (true) {
            if (umap['b'] > 0) {
                umap['b']--;
            } else {
                return count;
            }
            if (umap['a'] > 0) {
                umap['a']--;
            } else {
                return count;
            }
            if (umap['l'] > 1) {
                umap['l'] -= 2;
            } else {
                return count;
            }
            if (umap['o'] > 1) {
                umap['o'] -= 2;
            } else {
                return count;
            }
            if (umap['n'] > 0) {
                umap['n']--;
            } else {
                return count;
            }
            count++;
        }
        return count;
    }
};