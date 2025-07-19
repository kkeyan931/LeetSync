class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int maxi = 0;
        int maxFreq = 0;

        unordered_map<char, int> freqMap;

        while(ptr2 < n) {
            freqMap[s[ptr2]]++;

            maxFreq = max(maxFreq, freqMap[s[ptr2]]);

            // while can be converted to if
            while(ptr2 - ptr1 + 1 - maxFreq > k) {
                freqMap[s[ptr1]]--;
                maxFreq = 0;

                // this updation to maxFreq can be removed
                for(auto [ch, freq] : freqMap) {
                    maxFreq = max(maxFreq, freq);
                }
                ptr1++;
            }
            maxi = max(maxi, ptr2 - ptr1 + 1);

            ptr2++;
        }

        return maxi;
    }
};