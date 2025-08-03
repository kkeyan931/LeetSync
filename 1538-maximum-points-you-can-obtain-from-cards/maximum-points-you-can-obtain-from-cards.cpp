class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        /*
            constant window
        */

        int n = cardPoints.size();
        if(k == n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int sum = 0;
        for(int i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }

        int maxi = sum;
        int left = k - 1;
        for(int right = n - 1; right >= n - k; --right) {
            sum -= cardPoints[left--];
            sum += cardPoints[right];

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};