
class Solution {
public:
    vector<int> parent;

    int find(int x) 
    {
        if (parent[x] != x) 
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int root1 = find(edge[0]);
            int root2 = find(edge[1]);

            if (root1 == root2) 
            {
                return edge;
            }

            parent[root1] = root2;
        }

        return {};
    }
};