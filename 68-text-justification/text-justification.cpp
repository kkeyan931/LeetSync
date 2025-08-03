class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // 1) Determine how many words fit on this line
            int totalChars = words[i].size();
            int j = i + 1;
            while (j < n && totalChars + 1 + words[j].size() <= maxWidth) {
                totalChars += 1 + words[j].size();
                ++j;
            }

            int cnt = j - i;    // number of words on this line
            int gaps = cnt - 1; // number of spaces between words
            string line;

            // 2a) Last line or single-word line: left-justify
            if (j == n || gaps == 0) {
                // join with single spaces
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k + 1 < j)
                        line += ' ';
                }
                // pad the rest
                line += string(maxWidth - line.size(), ' ');
            } else {
                // 2b) Fully justify
                int spacesNeeded = maxWidth - (totalChars - gaps);
                int spaceWidth = spacesNeeded / gaps;
                int extraSpaces = spacesNeeded % gaps;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k + 1 < j) {
                        // distribute extra spaces to the leftmost gaps
                        int thisGap =
                            spaceWidth + ((k - i) < extraSpaces ? 1 : 0);
                        line += string(thisGap, ' ');
                    }
                }
            }

            result.push_back(move(line));
            i = j; // advance to the next group of words
        }

        return result;
    }
};
