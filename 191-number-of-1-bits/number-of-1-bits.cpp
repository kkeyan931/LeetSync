class Solution {
public:
    int hammingWeight(int n) {
        
        int result = 0;
        for(int i = 32 - 1; i >= 0; i--) {
            bool bit = n & 1 << i;
            result += bit;
        }

        return result;
    }
};