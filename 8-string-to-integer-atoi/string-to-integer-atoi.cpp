class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long ans = 0;
        bool isNeg = false;
        bool signCompleted = false;
        while (i < s.length() && signCompleted != true &&
               (s[i] == '-' || s[i] == '+' || s[i] == ' ')) {
            if (s[i] == '-')
                isNeg = true;
            if (s[i] == '-' || s[i] == '+') {
                signCompleted = true;
            }
            i++;
        }
        while (i < s.length() && s[i] >= 48 && s[i] <= 57) {
            if (ans * 10 >= INT_MAX)
                if (isNeg)
                    return INT_MIN;
                else
                    return INT_MAX;
            ans = ((ans * 10) + (s[i] - '0'));
            i++;
        }
        if (ans > INT_MAX)
            if (isNeg)
                return INT_MIN;
            else
                return INT_MAX;
        if (isNeg)
            return -ans;
        return ans;
    }
};