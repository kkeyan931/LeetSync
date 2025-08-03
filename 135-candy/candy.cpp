class Solution {
public:
    int brute(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n);

        left[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        vector<int> right(n);

        right[n - 1] = 1;

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += max(left[i], right[i]);
        }

        return sum;
    }
    int optimal(vector<int>& ratings) {

        int n = ratings.size();

        int sum = 1;
        int i = 1;

        while (i < n) {

            while (i < n && ratings[i - 1] == ratings[i]) {
                sum += 1;
                i++;
            }

            int peek = 1;

            while (i < n && ratings[i] > ratings[i - 1]) {
                peek++;
                sum += peek;
                i++;
            }

            int down = 1;

            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                down++;
                i++;
            }

            if (down > peek) {
                sum += (down - peek);
            }
        }
        return sum;
    }
    int candy(vector<int>& ratings) { 
        // return brute(ratings); 
        return optimal(ratings);
    }
};