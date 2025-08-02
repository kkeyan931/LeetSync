class Solution {
public:
    long reverse(int x) {
        long rev = 0;

        while (x > 0) {
            int lastDigit = x % 10;
            rev = (rev * 10) + lastDigit;
            x = x / 10;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        return reverse(x) == x;
    }
};