class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> A(255);
        vector<int> B(255);

        for(auto ch : s) {
            A[ch]++;
        }
        for(auto ch : t) {
            B[ch]++;
        }
        return A == B;
    }
};