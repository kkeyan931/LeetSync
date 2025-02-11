class Solution {
public:
    bool canPlace(vector<int>& position, int distance, int balls) {
        int countBalls = 1, lastBall = position[0];

        for(int i=1;i<position.size();i++) {
            if(position[i]-lastBall >= distance) {
                countBalls++;
                lastBall = position[i];
            }
            if(countBalls >= balls) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int balls) {
        int n = position.size();

        sort(position.begin(), position.end());
        int start = 1, end = position[n-1] - position[0];

        int result = 1;
        while(start<=end) {
            int mid = start + ((end-start) / 2);

            if(canPlace(position, mid, balls)) {
                start = mid+1;
                result = max(result, mid);
            } else {
                end = mid - 1;
            }
        }
        return result;
    }
};