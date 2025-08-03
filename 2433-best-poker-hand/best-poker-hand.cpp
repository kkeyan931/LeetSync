class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        char check = suits[0];
        bool valid = true;
        for (int i = 1; i < 5; ++i) {
            if (suits[i] != check) {
                valid = false;
                break;
            }
        }
        if (valid)
            return "Flush";
        int set[14] = {0}, maxi = 0;
        for (int i = 0; i < 5; ++i)
            maxi = max(maxi, ++set[ranks[i]]);
        if (maxi > 2)
            return "Three of a Kind";
        if (maxi == 2)
            return "Pair";
        return "High Card";
    }
};