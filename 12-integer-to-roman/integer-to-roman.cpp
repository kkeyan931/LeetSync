class Solution {
public:
    string intToRoman(int num) {
        vector<int> arr = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
        vector<string> str = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};

        string result;

        for (int i = 0; i < arr.size(); i++) {
            if (num == 0)
                break;

            int times = num / arr[i];
            for (int j = 0; j < times; j++) {
                result += str[i];
            }

            num = num % arr[i];
        }

        return result;
    }
};