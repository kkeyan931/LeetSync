class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<int> table1(26);
        vector<int> table2(26);

        for (int i = 0; i < n; ++i) {
            table1[s1[i] - 'a']++;
        }

        for (int i = 0; i < m; ++i) {
            table2[s2[i] - 'a']++;

            if (i >= n) {
                table2[s2[i - n] - 'a']--;
            }

            if (table1 == table2)
                return true;
        }
        return false;
    }
};