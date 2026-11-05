class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            pair<int, vector<int>> p = {dist, {x, y}};

            minHeap.push(p);
        }
        vector<vector<int>> result;

        for (int i = 0; i < k; i++)
        {
            pair<int, vector<int>> p = minHeap.top();
            minHeap.pop();

            result.push_back(p.second);
        }

        return result;

    }
};
