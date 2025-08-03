class Solution {
public:
    vector<int> getNumbers(int n) {

        vector<int> nums;

        while (n > 0) {
            nums.push_back(n % 10);
            n = n / 10;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
    int nextGreaterElement(int number) {
        /*
            next permutation
        */

        /*
            1. try to find the longest prefix that can be a match
            2. swap the break index with the smallest grestest element
            3. reverse the other half
        */

        vector<int> nums = getNumbers(number);
        int n = nums.size();

        int ind = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }


        if (ind == -1) {
            return -1;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        int i = ind + 1;
        int j = n - 1;

        while (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        long long sum = 0;
        long long roll = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            sum = sum + nums[i] * roll;

            if(sum > INT_MAX) {
                return -1;
            }

            roll = roll * 10;
        }
        return (int)sum;
    }
};