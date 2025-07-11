class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int n = points.size();
        
        for(int i=0;i<n;++i){
            pq.push({pow(points[i][0],2)+pow(points[i][1],2),i});
        }
        
        vector<vector<int>> result;
        
        while(k--){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return result;
        
    }
};