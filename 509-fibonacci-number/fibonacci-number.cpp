class Solution {
public:

    int rec(int n, vector<int> &mem) {
        if(n==0) return 0;
        if(n<=2) return 1;

        if(mem[n] != 0) return mem[n];

        return mem[n] = rec(n-1, mem) + rec(n-2, mem);
    }
    int it(int n) {

        if(n == 0) return 0;
        
        int a = 0, b = 1;

        int pos = 2;
        while(pos<=n) {
            int temp = b;
            b = a + b;
            a = temp;
            pos++;
        }
        return b;
    }
    int fib(int n) {
        // vector<int> mem(n+1, 0);
        // return rec(n, mem);

        return it(n);
    }
};