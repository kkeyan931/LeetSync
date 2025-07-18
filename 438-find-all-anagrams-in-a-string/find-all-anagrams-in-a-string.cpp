class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        if(s.size() < p.size())
           return {};

        vector<int> pv(26, 0);
        vector<int> sv(26, 0);

        vector<int> res;

        for (int i = 0; i < p.size(); ++i) {
            ++pv[p[i] - 'a'];
            ++sv[s[i] - 'a'];
        }

        if (pv == sv)
            res.push_back(0);

        for (int i = p.size(); i < s.size(); ++i) {
            ++sv[s[i] - 'a'];

            --sv[s[i - p.size()] - 'a'];

            if (pv == sv)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};