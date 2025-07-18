class Solution {
public:
    string reorganizeString(string s) {

        int n = s.size();

        unordered_map<char, int> umap;

        for (auto ch : s) {
            umap[ch]++;
            if (umap[ch] > (n + 1) / 2) {
                return "";
            }
        }
        priority_queue<pair<int, char>> pq;

        for (auto [ch, count] : umap) {
            pq.push({count, ch});
        }
        vector<char> result(n);

        int i = 0;
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            while (count--) {
                result[i] = ch;
                i += 2;

                if (i >= n) {
                    i = 1;
                }
            }
        }
        string str(result.begin(), result.end());
        return str;
    }
};