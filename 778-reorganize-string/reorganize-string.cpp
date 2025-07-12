class Solution {
public:
    string reorganizeString(string s) {

        priority_queue<pair<int,char>> pq;
        
        unordered_map<char,int> umap;

        for(auto ch : s) {
            umap[ch]++;
        }

        int maxi = 1;
        for(auto [key, count] : umap) {
            pq.push({count, key});
            maxi = max(maxi, count);
        }

        if(maxi > (s.size() + 1) / 2) {
            return "";
        }
        int index = 0;
        while(!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            
            while(count--) {
                s[index] = ch;
                index += 2;
                if(index >= s.size()) {
                    index = 1;
                }
            }
        }
        return s;
    }
};