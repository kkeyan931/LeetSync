class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> counter(255);

        for(auto ch : s) {
            counter[ch]++;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(counter[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};