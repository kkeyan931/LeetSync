class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;

        for(int i = 0; i < s.size(); ++i) {
            if(!stack.empty() && s[i] == '*') {
                stack.pop();
                continue;
            }
            stack.push(s[i]);
        }
        string result = "";

        while(!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};