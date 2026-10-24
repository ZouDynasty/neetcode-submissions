class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int cur_streak = 1;

        int max_inc_streak = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                cur_streak++;
            }
            else
            {
                max_inc_streak = max(max_inc_streak, cur_streak);
                cur_streak = 1;
            }
        }

        max_inc_streak = max(max_inc_streak, cur_streak);

        cur_streak = 1;

        int max_dec_streak = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                cur_streak++;
            }
            else
            {
                max_dec_streak = max(max_dec_streak, cur_streak);
                cur_streak = 1;
            }
        }

        max_dec_streak = max(max_dec_streak, cur_streak);

        return max(max_inc_streak, max_dec_streak);
        
    }
};