class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));

        for(int i = 0; i < times.size(); i++)
        {
            int x = times[i][0];
            int y = times[i][1];
            int weight = times[i][2];

            graph[x][y] = weight;
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        dfs(k, dist, graph);

        int max = 0;
        for (int i = 1; i < dist.size(); i++)
        {
            if (dist[i] == INT_MAX)
            {
                return -1;
            }
            else if (dist[i] > max)
            {
                max = dist[i];
            }
        }
        return max;
    }
    
    void dfs(int cur, vector<int>& dist, vector<vector<int>>& graph)
    {
        int neighbors_updated = 0;
        for (int neighbor = 0; neighbor < graph[cur].size(); neighbor++)
        {
            if (graph[cur][neighbor] >= 0)
            {
                if (dist[cur] + graph[cur][neighbor] < dist[neighbor])
                {
                    dist[neighbor] = dist[cur] + graph[cur][neighbor];
                    dfs(neighbor, dist, graph);
                }
            }
        }
        return;
    }
};
