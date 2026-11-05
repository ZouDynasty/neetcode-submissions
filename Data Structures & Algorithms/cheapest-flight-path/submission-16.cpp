class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& flight : flights)
        {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);

        dfs(src, dst, dist, 0, 0, k, graph);

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }

    void dfs(int cur, int dst, vector<int>& dist, int stops,
             int current_cost, int k,
             vector<vector<pair<int, int>>>& graph)
    {
        if (stops > k + 1)
        {
            return;
        }

        if (cur == dst)
        {
            dist[dst] = min(dist[dst], current_cost);
            return;
        }

        for (auto neighbor : graph[cur])
        {
            int new_cost = current_cost + neighbor.second;

            if (new_cost >= dist[dst])
            {
                continue;
            }

            dfs(neighbor.first, dst, dist, stops + 1,
                new_cost, k, graph);
        }
    }
};