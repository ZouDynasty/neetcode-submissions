class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int count = 0;

        vector<int> visited(n);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count = count + 1;
                dfs(graph, i, visited);
            }
        }

        return count;



    }

private:
    void dfs(vector<vector<int>>& graph, int start, vector<int>& visited)
    {
        if (visited[start] == 1)
        {
            return;
        }
        else
        {
            visited[start] = 1;
            for (int i = 0; i < graph[start].size(); i++)
            {
               dfs(graph, graph[start][i], visited);
            } 
        }
    }
};
