class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqMap;
        for (char task : tasks)
            freqMap[task]++;

        priority_queue<int> pq;
        for (auto& [_, freq] : freqMap)
            pq.push(freq);

        queue<pair<int, int>> cooldown; // {ready time, freq}

        int time = 0;
        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }

            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                if (freq > 1)
                    cooldown.push({time + n + 1, freq - 1});
            }
        }

        return time;
    }
};
