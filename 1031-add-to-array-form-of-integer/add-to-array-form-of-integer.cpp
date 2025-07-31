class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();

        vector<int> result;
        
        int i = n - 1;
        int carry = 0;
        while(i >= 0 || k > 0 || carry) {
            int digit = k % 10;
            k = k / 10;

            int sum = carry + digit;
            if(i >= 0) {
                sum += num[i];
            }
            i--;
            carry = sum / 10;
            
            result.push_back(sum % 10);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};