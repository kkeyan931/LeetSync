class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> umap;

        int ptr1 = 0;
        int ptr2 = 0;

        int maxi = 0;
        while (ptr2 < s.size()) {
            umap[s[ptr2]]++;

            while (umap[s[ptr2]] > 1) {
                umap[s[ptr1]]--;
                ptr1++;
            }
            maxi = max(maxi, ptr2 - ptr1 + 1);
            ptr2++;
        }
        return maxi;
    }
};