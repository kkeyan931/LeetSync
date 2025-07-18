class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int n1 = ransomNote.size();
        int n2 = magazine.size();

        if(n1 > n2) {
            return false;
        }

        unordered_map<int, int> umap1;
        unordered_map<int, int> umap2;

        for(auto ch : ransomNote) {
            umap1[ch]++;
        }
        for(auto ch : magazine) {
            umap2[ch]++;
        }

        for(auto [ch, count] : umap1) {
            if(umap2[ch] < count) {
                return false;
            }
        }
        return true;
    }
};