class Solution {
public:
    int getNumIndex(vector<int> &nums, int i)
    {
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] != INT_MIN)
                return i;
            i++;
        }
        return -1;
    }
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int removeDuplicates(vector<int> &nums)
    {

        int n = nums.size();
        if (n <= 1)
            return n;

        int i = 0, j = 1;

        int k = 1;
        while (j < n)
        {
            if (nums[i] == nums[j])
            {
                nums[j] = INT_MIN;
                j++;
            }
            else
            {
                k++;
                i = j;
                j++;
            }
        }

        i = 0;
        while (i < n)
        {
            if (nums[i] == INT_MIN)
            {
                int j = getNumIndex(nums, i + 1);
                if (j != -1)
                {
                    swap(nums, i, j);
                    i++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            i++;
        }
        return k;
    }
};