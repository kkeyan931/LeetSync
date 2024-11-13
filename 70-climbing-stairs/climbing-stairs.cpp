class Solution {
public:
    int recHelper(int n, vector<int>& table) {
        if (n <= 2)
            return table[n - 1] = n;

        if (table[n - 1] != 0)
            return table[n - 1];

        return table[n - 1] = recHelper(n - 1, table) + recHelper(n - 2, table);
    }
    int twoVarHelper(int n) {

        if(n <= 2) return n;
        int stepOne = 1;
        int stepTwo = 2;

        int result = 0;
        for(int it=3; it<=n; it++) {

            result = stepOne + stepTwo;
            stepOne = stepTwo;
            stepTwo = result;
        }
        return result;
    }
    int climbStairs(int n) {
        vector<int> table(n, 0);
        // return recHelper(n, table);
        return twoVarHelper(n);
    }
};