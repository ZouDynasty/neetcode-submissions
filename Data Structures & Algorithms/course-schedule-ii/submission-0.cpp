class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            indegree[course]++;
            int prereq = prerequisites[i][1];

            graph[prereq].push_back(course);
        }

        queue<int> q;

        vector<int> path;

        for(int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                path.push_back(i);
                q.push(i);
            }
        }

        while(q.size() > 0)
        {
            int cur = q.front();
            q.pop();

            for (int neighbor : graph[cur])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    path.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }

        if (path.size() == numCourses)
        {
            return path;
        }

        return {};

    }
};
