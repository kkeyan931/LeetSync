class Solution {
public:
    bool canShip(vector<int>& weights, long long capacity, int days) {

        int countDays = 1, weightAccumulator = 0;
        for (auto& weight : weights) {

            if (weightAccumulator + weight <= capacity) {
                weightAccumulator += weight;
            } else {
                countDays++;
                weightAccumulator = weight;
            }
            if (weightAccumulator > capacity)
                return false;
        }

        return countDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        long long sum = accumulate(weights.begin(), weights.end(), 0);
        int max = *max_element(weights.begin(), weights.end());
        if (days == 1) {
            return sum;
        }

        long long start = max, end = sum;

        long long minCapacity = sum;
        while (start < end) {
            long long mid = (start + end)/2;

            if (canShip(weights, mid, days)) {
                minCapacity = min(minCapacity, mid);
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return minCapacity;
    }
};