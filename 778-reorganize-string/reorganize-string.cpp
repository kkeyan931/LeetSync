class Solution {
public:
    string solution1(string s) {
        int n = s.size();
        unordered_map<char, int> umap;

        for (auto ch : s) {
            umap[ch]++;
            if (umap[ch] > (n + 1) / 2) {
                return "";
            }
        }
        priority_queue<pair<int, char>> pq;

        for (auto [ch, count] : umap) {
            pq.push({count, ch});
        }
        vector<char> result(n);

        int i = 0;
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            while (count--) {
                result[i] = ch;
                i += 2;

                if (i >= n) {
                    i = 1;
                }
            }
        }
        string str(result.begin(), result.end());
        return str;
    }
    string solution2(string inputString) {
        vector<int> charCounter(26, 0);

        for (char character : inputString) {
            charCounter[character - 'a']++;
        }

        int maxCount = 0, maxLetter = 0;
        for (int index = 0; index < charCounter.size(); index++) {
            if (charCounter[index] > maxCount) {
                maxCount = charCounter[index];
                maxLetter = index;
            }
        }

        if (maxCount > (inputString.length() + 1) / 2) {
            return "";
        }

        vector<char> result(inputString.size());
        int resultIterator = 0;

        // Place the most frequent letter
        while (charCounter[maxLetter] != 0) {
            result[resultIterator] = char(maxLetter + 'a');
            resultIterator += 2;
            charCounter[maxLetter]--;
        }

        // Place rest of the letters in any order
        for (int index = 0; index < charCounter.size(); index++) {
            while (charCounter[index] > 0) {
                if (resultIterator >= inputString.length()) {
                    resultIterator = 1;
                }
                result[resultIterator] = char(index + 'a');
                resultIterator += 2;
                charCounter[index]--;
            }
        }
        string resultString(result.begin(), result.end());
        return resultString;
    }
    string reorganizeString(string s) {
        // return solution1(s);
        return solution2(s);
    }
};