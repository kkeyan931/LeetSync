class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char> stack;
        unordered_map<char, int> lastIndex;
        unordered_set<char> seen;

        for(int i = 0; i < s.size(); ++i) {
            lastIndex[s[i]] = i;
        }

        for(int i = 0; i < s.size(); ++i) {

            if(seen.find(s[i]) == seen.end()) {

                while(!stack.empty() && lastIndex[stack.top()] > i && s[i] < stack.top()) {
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(s[i]);
                stack.push(s[i]);
            }
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