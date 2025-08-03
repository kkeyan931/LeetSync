class Solution {
public:
    int dfs(vector<int>& bits, vector<array<int, 2>>& memo, int i, int carry) {
        if (i == bits.size())
            return carry; // if carry remains, needs one more op at a new top
                          // bit
        if (memo[i][carry] != -1)
            return memo[i][carry];

        int v = bits[i] + carry; // 0,1,2
        int res;
        if (v == 0) {
            res = dfs(bits, memo, i + 1, 0);
        } else if (v == 2) {
            // 2*2^i == 0 at this bit with carry 1 to next; no op here
            res = dfs(bits, memo, i + 1, 1);
        } else {
            // v == 1 → must choose add or subtract (both cost 1 op)
            int subtractHere = dfs(bits, memo, i + 1, 0); // choose s_i = +1 (subtract 2^i)
            int addHere =
                dfs(bits, memo, i + 1, 1); // choose s_i = -1 (add 2^i, carry forward)
            res = 1 + min(subtractHere, addHere);
        }
        return memo[i][carry] = res;
    }
    int mem(int n) {
        if (n == 0)
            return 0;
        // Extract bits of n (LSB -> MSB)
        vector<int> bits;
        while (n > 0) {
            bits.push_back(n & 1);
            n >>= 1;
        }
        int m = (int)bits.size();
        // memo[i][carry]: -1 = uncomputed
        vector<array<int, 2>> memo(m + 1, array<int, 2>{-1, -1});
        return dfs(bits, memo, 0, 0);
    }
    int minOperations(int n) { return mem(n); }
};