class Solution {
public:
    int numSplits(string s) {
        
        unordered_map<char, int> amap;
        unordered_map<char, int> bmap;

        for(auto ch : s) {
            amap[ch]++;
        }

        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            bmap[s[i]]++;
            amap[s[i]]--;
            if(amap[s[i]] == 0) {
                amap.erase(s[i]);
            }
            if(amap.size() == bmap.size()) {
                count++;
            }
        }
        return count;
    }
};