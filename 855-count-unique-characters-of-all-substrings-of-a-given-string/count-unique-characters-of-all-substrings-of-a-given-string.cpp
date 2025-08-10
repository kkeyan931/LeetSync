class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> indexMap;

        // Store the indices of each character's occurrence in the string
        for (int index = 0; index < s.size(); ++index) {
            indexMap[s[index]].push_back(index);
        }

        int ans = 0;

        // Traverse the index map to compute the contribution of each character
        for (auto& [character, charIndexes] : indexMap) {
            // Add -1 and s.size() as padding for easier handling of first and
            // last occurrences
            charIndexes.insert(charIndexes.begin(), -1);
            charIndexes.push_back(s.size());

            // Now compute the contribution of each occurrence of the character
            for (int i = 1; i < charIndexes.size() - 1; ++i) {
                int prev = charIndexes[i - 1];
                int next = charIndexes[i + 1];

                // Each occurrence contributes (current index - prev) * (next -
                // current index)
                ans += (charIndexes[i] - prev) * (next - charIndexes[i]);
            }
        }
        return ans;
    }
};
