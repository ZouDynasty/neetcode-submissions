/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [] (Interval& a, Interval& b)
        {
            return (a.start < b.start);
        }
        );

        vector<int> start_sorted;

        for (int i = 0; i < intervals.size(); i++)
        {
            start_sorted.push_back(intervals[i].start);
        }

        sort(intervals.begin(), intervals.end(), [] (Interval& a, Interval& b)
        {
            return (a.end < b.end);
        }
        );

        vector<int> end_sorted;

        for (int i = 0; i < intervals.size(); i++)
        {
            end_sorted.push_back(intervals[i].end);
        }

        int s = 0;
        int e = 0;

        int max_concurrent = 0;
        int concurrent = 0;

        while (s < intervals.size())
        {
            if (start_sorted[s] < end_sorted[e])
            {
                concurrent++;
                max_concurrent = max(max_concurrent, concurrent);
                s++;
            }
            else
            {
                e++;
                concurrent--;
            }
        }
        return max_concurrent;
    }
};

// (0,4), (1,5), (2, 6), (5, 10)

// start: (0, 1, 2, 5)
// end: (4, 5, 6, 10)
