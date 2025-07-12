struct comp {
    const bool operator()(const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> umap;

        for(auto ch : s) {
            umap[ch]++;
        }

        vector<pair<char,int>> arr;

        for(auto [key, count] : umap) {
            arr.push_back({key, count});
        }
        sort(arr.begin(), arr.end(), comp{});

        string result = "";
        for(auto [key, count] : arr) {
            while(count--) {
                result += key;
            }
        }
        return result;
    }
};