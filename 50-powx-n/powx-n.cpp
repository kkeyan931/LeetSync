class Solution {
public:
    double helper(double x, long long n) {
        if (n == 1)
            return x;
        if (n == 0)
            return 1.0;

        if (n % 2ll == 0.0) {
            return helper(x * x, n / 2ll);
        }
        return x * helper(x, n - 1);
    }
    double myPow(double x, int n) {
        if (n < 0) {
            return (1.0 / helper(x, -1ll * n));
        }
        return helper(x, n);
    }
};