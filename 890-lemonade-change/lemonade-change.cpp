class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;
        int twenty = 0;

        for (int index = 0; index < bills.size(); ++index) {
            if (bills[index] == 5) {
                five++;
            } else if (bills[index] == 10) {
                if (five > 0) {
                    five--;
                } else {
                    return false;
                }
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    ten--;
                    five--;
                } else if (five > 2) {
                    five -= 3;
                } else {
                    return false;
                }
                twenty++;
            }
        }
        return true;
    }
};