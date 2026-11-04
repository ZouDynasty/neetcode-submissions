class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            indegree[course]++;
            int prereq = prerequisites[i][1];

            graph[prereq][course]++;
        }

        queue<int> q;

        int processed = 0;

        for(int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                processed++;
            }
        }

        while(q.size() > 0)
        {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < graph.size(); i++)
            {
                if (graph[cur][i] == 1)
                {
                    indegree[i]--;
                    if (indegree[i] == 0)
                    {
                        q.push(i);
                        processed++;
                    }
                }
            }
        }

        return processed == numCourses;

    }
};
