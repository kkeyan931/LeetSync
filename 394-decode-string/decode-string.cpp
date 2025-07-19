class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ']') {
                string decodedString = "";

                // get the string inside []
                while (!st.empty() && st.top() != "[") {
                    decodedString = st.top() + decodedString;
                    st.pop();
                }

                // pop the '['
                if (!st.empty())
                    st.pop();

                // get the number
                string digitStr = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    digitStr = st.top() + digitStr;
                    st.pop();
                }

                int digit = stoi(digitStr);

                // repeat and push back
                string temp = "";
                for (int j = 0; j < digit; ++j) {
                    temp += decodedString;
                }
                st.push(temp);
            } else {
                st.push(string(1, s[i]));
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
