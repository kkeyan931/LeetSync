class Solution {
public:
    string solution1(string s) {
        priority_queue<vector<int>> pq;

        unordered_map<char, int> umap;

        for (auto ch : s) {
            umap[ch]++;
        }

        int maxi = 1;
        for (auto [key, count] : umap) {
            pq.push({count, key});
            maxi = max(maxi, count);
        }

        if (maxi > (s.size() + 1) / 2) {
            return "";
        }

        string result = "";
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();

            if (result.empty() || first[1] != result.back()) {
                result += char(first[1]);
                if (--first[0] > 0) {
                    pq.push(first);
                }
            } else {
                auto second = pq.top();
                pq.pop();
                result += char(second[1]);
                if (--second[0] > 0) {
                    pq.push(second);
                }
                pq.push(first);
            }
        }
        return result;
    }
    string reorganizeString(string s) { return solution1(s); }
};