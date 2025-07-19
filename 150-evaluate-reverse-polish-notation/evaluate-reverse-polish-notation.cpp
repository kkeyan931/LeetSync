class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stack;

        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();

                if (tokens[i] == "+") {
                    stack.push(a + b);
                }
                if (tokens[i] == "-") {
                    stack.push(a - b);
                }
                if (tokens[i] == "*") {
                    stack.push(a * b);
                }
                if (tokens[i] == "/") {
                    stack.push(a / b);
                }
            } else {
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};