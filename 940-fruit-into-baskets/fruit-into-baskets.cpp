class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        int ptr1 = 0;
        int ptr2 = 0;

        unordered_map<int, int> umap;

        int maxi = 1;
        while (ptr2 < n) {
            umap[fruits[ptr2]]++;

            if (umap.size() > 2) {
                umap[fruits[ptr1]]--;

                if (umap[fruits[ptr1]] == 0) {
                    umap.erase(fruits[ptr1]);
                }
                ptr1++;
            }
            maxi = max(maxi, ptr2 - ptr1 + 1);
            ptr2++;
        }
        return maxi;
    }
};