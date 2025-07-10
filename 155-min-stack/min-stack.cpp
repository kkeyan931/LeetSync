class MinStack {
public:
    stack<pair<int, int>> stack;
    MinStack() {}

    void push(int val) {
        if (stack.empty()) {
            stack.push({val, val});
            return;
        }
        stack.push({val, min(val, stack.top().second)});
    }

    void pop() {
        if (stack.empty()) {
            return;
        }
        stack.pop();
    }

    int top() {
        if (stack.empty()) {
            return -1;
        }
        return stack.top().first;
    }

    int getMin() {
        if (stack.empty()) {
            return -1;
        }
        return stack.top().second;
    }
};
