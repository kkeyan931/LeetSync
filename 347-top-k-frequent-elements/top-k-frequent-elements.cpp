class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        
        for(auto &num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result;

        for(auto [key, count] : freqMap) {
            pq.push({count, key});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};