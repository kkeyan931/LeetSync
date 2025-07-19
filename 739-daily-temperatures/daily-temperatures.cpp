class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> result(n, 0);

        stack<int> stack;
        for(int i = n - 1; i >= 0; --i) {
            while(!stack.empty() && temperatures[stack.top()] <= temperatures[i]) {
                stack.pop();
            }
            if(stack.empty()) {
                result[i] = 0;
            } else {
                result[i] = stack.top() - i;
            }
            stack.push(i);
        }
        return result;
    }
};