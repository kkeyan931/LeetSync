class Solution {
public:
    bool isValid(string word) {

        if (word.size() < 3) { // edge case
            return false;
        }

        bool has_vowel = false;
        bool has_consonant = false;
        for (auto c : word) {
            if (isalpha(c)) { // alphabet character or not
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) { // digit or not
                return false;
            }
        }
        return has_vowel &&
               has_consonant; // when vowel and consonent true -> true
    }
};