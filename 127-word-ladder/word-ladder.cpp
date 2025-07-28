class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> wordListSet(wordList.begin(), wordList.end());

        if (wordListSet.find(endWord) == wordListSet.end()) {
            return 0;
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int count = 1;
        while (!q.empty()) {

            int size = q.size();

            while (size--) {
                string str = q.front();
                q.pop();

                if (str == endWord) {
                    return count;
                }
                for (int i = 0; i < str.size(); ++i) {
                    string clone = str;
                    for (int ch = 'a'; ch <= 'z'; ++ch) {
                        clone[i] = ch;

                        if (visited.find(clone) != visited.end()) {
                            continue;
                        }
                        if (wordListSet.find(clone) == wordListSet.end()) {
                            continue;
                        }
                        visited.insert(clone);
                        q.push(clone);
                    }
                }
            }
            count++;
        }

        return 0;
    }
};