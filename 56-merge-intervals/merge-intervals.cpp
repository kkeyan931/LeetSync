class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0]<b[0]) return true;
        if(a[0]>b[0]) return false;
        if(a[0]==b[0]) return a[1]<b[1];
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int n = intervals.size();
        if(n==1) return intervals;

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=1;i<n;++i) {
            auto &back = result.back();
            auto &current = intervals[i];

            if(back[1]>=current[0]) {
                back[1] = back[1] > current[1] ? back[1] : current[1];
            } else {
                result.push_back(current);
            }
        }
        return result;
    }
};