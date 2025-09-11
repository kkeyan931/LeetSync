class Solution {
public:
    bool kahnAlgo(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int preCourse = prerequisite[1];

            adjList[preCourse].push_back(course);
            indegree[course]++;
        }

        queue<int> courseQueue;

        for (int course = 0; course < numCourses; ++course)
            if (indegree[course] == 0) {
                courseQueue.push(course);
            }

        int visitedCourse = 0;
        while (!courseQueue.empty()) {

            int currentCourse = courseQueue.front();
            courseQueue.pop();
            visitedCourse++;

            for (int nextCourse : adjList[currentCourse]) {
                if (--indegree[nextCourse] == 0) {
                    courseQueue.push(nextCourse);
                }
            }
        }
        return visitedCourse == numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return kahnAlgo(numCourses, prerequisites);
    }
};