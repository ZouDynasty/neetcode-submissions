class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int> temp = dist;
            for (int i = 0; i < flights.size(); i++)
            {
                int from = flights[i][0];
                int to = flights[i][1];
                int price = flights[i][2];

                if (dist[from] == INT_MAX)
                {
                    continue;
                }
                temp[to] = min(temp[to], dist[from] + price);
            }  
            dist = temp;
        }
        if (dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};