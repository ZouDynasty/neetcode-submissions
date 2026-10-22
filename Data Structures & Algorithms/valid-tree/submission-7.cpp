class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        set<int> visited;

        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];

            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        bool foundCycle = false;
        
        dfs(0, -1, graph, visited, foundCycle);

        if (foundCycle)
        {
            return false;
        }

        if (visited.size() < n)
        {
            return false;
        }

        return true;

    }
    void dfs(int start, int parent, vector<vector<int>>& graph, set<int>& visited, bool& foundCycle)
    {
        if (visited.find(start) != visited.end())
        {
            foundCycle = true;
            return;
        }

        visited.insert(start);

        for (int i = 0; i < graph.size(); i++)
        {
            if(graph[start][i] == 1)
            {
                if (i != parent)
                {
                    dfs(i, start, graph, visited, foundCycle);
                }
            }

        }

        return;
    }
};
