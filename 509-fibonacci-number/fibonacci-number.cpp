class Solution {
public:

    int rec(int n, vector<int> &mem) {
        if(n==0) return 0;
        if(n<=2) return 1;

        if(mem[n] != 0) return mem[n];

        return mem[n] = rec(n-1, mem) + rec(n-2, mem);
    }
    int fib(int n) {
        vector<int> mem(n+1, 0);
        return rec(n, mem);
    }
};