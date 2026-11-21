class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0;
        int max_len = 0;
        int last_seen[128] = {};

        for (int r = 0; r < s.size(); r++)
        {
            l = max(l, last_seen[s[r]]);

            max_len = max(max_len, r - l + 1);

            last_seen[s[r]] = r + 1;
        }

        return max_len;
    }
};