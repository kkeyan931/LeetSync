class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ptr1 = 0;
        int ptr2 = height.size() - 1;

        int maxi = 0;
        while(ptr1 < ptr2) {
            maxi = max(maxi, min(height[ptr1], height[ptr2]) * (ptr2 - ptr1));

            if(height[ptr1] < height[ptr2]) {
                ptr1++;
            } else {
                ptr2--;
            }
        }
        return maxi;
    }
};