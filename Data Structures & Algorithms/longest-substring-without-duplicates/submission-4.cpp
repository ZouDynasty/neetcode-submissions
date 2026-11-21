class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0;
        int max_len = 0;
        unordered_map<char, bool> diff;

        for (int r = 0; r < s.size(); r++)
        {
            while (diff.find(s[r]) != diff.end())
            {
                diff.erase(s[l]);
                l++;
            }
            diff[s[r]] = true;
            int len = r - l + 1;
            if (len > max_len)
            {
                max_len = len;
            }
        }
        return max_len;
    }
};