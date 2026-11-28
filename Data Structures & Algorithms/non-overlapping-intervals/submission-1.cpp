class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> no_overlap;

        int cur_end = intervals[0][1];
        int removed = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < cur_end)
            {
                cur_end = min(cur_end, intervals[i][1]);
                removed++;
            }
            else
            {
                cur_end = intervals[i][1];
            }
        }

        return removed;
    }
};

// [[0,2],[1,3],[2,4],[3,5],[4,6]]

// end = 2
// 1 < 2

// removed ++
// removed (1,3)