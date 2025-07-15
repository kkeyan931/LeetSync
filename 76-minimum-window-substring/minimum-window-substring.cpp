class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) {
            return "";
        }

        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;

        for (auto ch : t) {
            tmap[ch]++;
        }

        int ptr1 = 0, ptr2 = 0;
        int formed = 0, start = -1, min = INT_MAX;

        while (ptr2 < n) {
            smap[s[ptr2]]++;

            if (tmap.find(s[ptr2]) != tmap.end() &&
                smap[s[ptr2]] == tmap[s[ptr2]]) {
                formed++;
            }
            while (formed == tmap.size() && ptr1 <= ptr2) {
                smap[s[ptr1]]--;

                if (tmap.find(s[ptr1]) != tmap.end() &&
                    smap[s[ptr1]] < tmap[s[ptr1]]) {
                    formed--;
                }
                if ((ptr2 - ptr1) + 1 < min) {
                    min = (ptr2 - ptr1) + 1;
                    start = ptr1;
                }
                ptr1++;
            }
            ptr2++;
        }
        return start == -1 ? "" : s.substr(start, min);
    }
};