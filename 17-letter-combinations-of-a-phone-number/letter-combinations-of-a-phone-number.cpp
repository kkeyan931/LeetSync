class Solution {
public:
    void combinationsBuilder(string& digits, vector<string>& result,
                             string& builder,
                             unordered_map<char, string>& digitsMap,
                             int digitsIterator) {

        if (digitsIterator == digits.size()) {
            result.push_back(builder);
            return;
        }

        for (auto character : digitsMap[digits[digitsIterator]]) {
            builder.push_back(character);
            combinationsBuilder(digits, result, builder, digitsMap,
                                digitsIterator + 1);
            builder.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0) {
            return {};
        }

        vector<string> result;
        string builder;

        unordered_map<char, string> digitsMap;
        digitsMap['2'] = "abc";
        digitsMap['3'] = "def";
        digitsMap['4'] = "ghi";
        digitsMap['5'] = "jkl";
        digitsMap['6'] = "mno";
        digitsMap['7'] = "pqrs";
        digitsMap['8'] = "tuv";
        digitsMap['9'] = "wxyz";

        combinationsBuilder(digits, result, builder, digitsMap, 0);

        return result;
    }
};