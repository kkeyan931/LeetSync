class Solution {
public:
    // Step 4: Helper method to check if we can eat all piles in 'h' hours with
    // 'speed'
    bool canEatInTime(vector<int> &piles, int h, int speed) {
        int totalHours = 0;

        // Calculate the total hours needed to finish all piles at the given
        // speed
        for (int pile : piles) {
            totalHours += (pile + speed - 1) / speed; // Rounding up division
        }

        return totalHours <= h; // If total hours is within 'h', return true
    }
    int minEatingSpeed(vector<int> &piles, int h) {
        // Step 1: Find the maximum pile size, which is the upper bound for
        // eating speed
        int minSpeed = 1;
        int maxSpeed = 0;

        maxSpeed = *(max_element(piles.begin(), piles.end()));
        // Step 2: Perform binary search to find the optimal speed
        while (minSpeed < maxSpeed) {
            int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;

            // Step 3: Check if we can eat all piles within 'h' hours with
            // current speed 'midSpeed'
            if (canEatInTime(piles, h, midSpeed)) {
                maxSpeed = midSpeed; // We can finish in time, try slower speed
            } else {
                minSpeed = midSpeed + 1; // We need a faster speed
            }
        }

        return minSpeed; // minSpeed will be the result (optimal speed)
    }
};