struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(2);
    int value;
};
class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(int num) {

        TrieNode* ptr = root;
        for (int i = 31; i >= 0; --i) {
            bool bit = num & 1 << i;
            if (ptr->children[bit] == nullptr) {
                ptr->children[bit] = new TrieNode();
            }
            ptr = ptr->children[bit];
        }
        ptr->value = num;
    }
    int getMax(int num) {
        TrieNode* ptr = root;
        for (int i = 31; i >= 0; --i) {
            bool bit = num & 1 << i;
            if (ptr->children[1 - bit]) {
                ptr = ptr->children[1 - bit];
            } else {
                ptr = ptr->children[bit];
            }
        }
        return num ^ ptr->value;
    }
    int findMaximumXOR(vector<int>& nums) {

        for(auto num : nums) {
            insert(num);
        }

        int maxi = 0;
        for(auto num : nums) {
            maxi = max(maxi, getMax(num));
        }
        return maxi;
    }
};