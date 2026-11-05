class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int, int>>> graph(n + 1);

        for(int i = 0; i < times.size(); i++)
        {
            int x = times[i][0];
            int y = times[i][1];
            int weight = times[i][2];
            pair<int, int> p = {y, weight};

            graph[x].push_back(p);
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
    
    void dfs(int cur, vector<int>& dist, vector<vector<pair<int, int>>> graph)
    {
        int neighbors_updated = 0;
        for (pair<int, int> p: graph[cur])
        {
            int neighbor = p.first;
            if (p.second >= 0)
            {
                if (dist[cur] + p.second < dist[neighbor])
                {
                    dist[neighbor] = dist[cur] + p.second;
                    dfs(neighbor, dist, graph);
                }
            }
        }
        return;
    }
};
