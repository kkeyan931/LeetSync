class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 1) {
            return strs[0];
        }

        string smallest;
        int small = INT_MAX;

        for(int i = 0; i < strs.size(); ++i) {
            if(strs[i].size() < small) {
                small = strs[i].size();
                smallest = strs[i];
            }
        }

        stringstream ss;
        bool flag = false;
        for(int i = 0; i < smallest.size(); ++i) {
            for(int j = 0; j < strs.size(); ++j) {
                if(smallest[i] != strs[j][i]) {
                    flag = true;
                    break;

                }
            }
            if(flag) break;
            ss << smallest[i];
        }
        return ss.str();
    }
};