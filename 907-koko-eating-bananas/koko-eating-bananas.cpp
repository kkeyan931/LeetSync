class Solution {
public:
    int getTimeTook(vector<int>& piles, int speed) {

        int timeTook = 0;
        for (int bananaCount : piles) {
            timeTook += (bananaCount + speed - 1) / speed;
        }
        return timeTook;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        int maxEl = *(max_element(piles.begin(), piles.end()));

        int start = 1, end = maxEl;

        int result = maxEl;
        while (start < end) {
            int mid = start + ((end - start) / 2);
            int timeTook = getTimeTook(piles, mid);

            if (timeTook <= h) {
                result = min(result, mid);
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};