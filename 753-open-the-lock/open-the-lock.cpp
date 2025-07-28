class Solution {
public:
    vector<int> directions = {-1, 1};
    int doBFS(vector<string>& deadends, string& target) {

        queue<string> q;
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if(visited.find("0000") != visited.end()) {
            return -1;
        }

        q.push("0000");
        visited.insert("0000");
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto str = q.front();
                q.pop();

                if (str == target) {
                    return time;
                }
                for (int i = 0; i < 4; ++i) {
                    for (int d : directions) {
                        string strClone = str;
                        int next = (strClone[i] - '0') + d;
                        if (next < 0) {
                            next = 9;
                        }
                        if (next > 9) {
                            next = 0;
                        }
                        strClone[i] = next + '0';

                        if (visited.find(strClone) == visited.end()) {
                            visited.insert(strClone);
                            q.push(strClone);
                        }
                    }
                }
            }
            time++;
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        return doBFS(deadends, target);
    }
};