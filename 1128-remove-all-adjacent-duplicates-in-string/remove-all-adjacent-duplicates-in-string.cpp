class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;

        for(int i = 0; i < s.size(); ++i) {
            if(!stack.empty() && stack.top() == s[i]) {
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