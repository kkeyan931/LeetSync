class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int count = 0;
        unordered_map<int, int> umap;
        for(auto num : nums) {
            if(umap.find(num) != umap.end()) {
                count += umap[num];
            }
            umap[num]++;
        }
        return count;
    }
};