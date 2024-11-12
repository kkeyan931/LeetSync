class Solution {
public:
     
    int recHelper(int n, vector<int> &table) {
        if(n <= 2) return table[n-1] = n;

        if(table[n-1] != 0 ) return table[n-1];

        return table[n-1] = recHelper(n-1, table) + recHelper(n-2, table);
    }
    int climbStairs(int n) {
        vector<int> table(n, 0);
        return recHelper(n, table);
    }
};