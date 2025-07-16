class Solution {
public:
    struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a[1] < b[1];
        }
    };
    int usingpq(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp{});
        priority_queue<int> pq;

        int day = 0;
        for (auto& x : courses) {
            if (day + x[0] <= x[1]) {
                day += x[0];
                pq.push(x[0]);
            } else if (pq.size() && pq.top() > x[0]) {
                day = day + x[0] - pq.top();
                pq.pop();
                pq.push(x[0]);
            }
        }

        return pq.size();
    }
    int rec(vector<vector<int>>& courses, vector<vector<int>> &dp, int index, int time) {
        if (index == courses.size()) {
            return 0;
        }

        if(dp[index][time] != -1) {
            return dp[index][time];
        }

        int take = 0;
        if (courses[index][0] + time <= courses[index][1]) {
            take = 1 + rec(courses, dp, index + 1, time + courses[index][0]);
        }
        int notTake = rec(courses, dp, index + 1, time);

        return dp[index][time] = max(take, notTake);
    }
    int mem(vector<vector<int>>& courses) {

        /*
          1. why sort based on lastday?
              (a, x), (b, y)
              x < y

              take a first then b
              a + b > x && a + b <= y -> take both course a -> b not b -> a

              take b first then a -> one we can take

              a + b > y -> take only one

              Hence sort based on the lastDay and explore.
        */
        sort(courses.begin(), courses.end(), comp{});
        vector<vector<int>> dp(courses.size(), vector<int>(courses[courses.size() - 1][1] + 1, -1));
        return rec(courses, dp, 0, 0);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        // return mem(courses);
        return usingpq(courses);
    }
};