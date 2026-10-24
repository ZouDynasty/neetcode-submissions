class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        cur_streak = 1
        max_inc_streak = 0
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                cur_streak += 1
            else:
                max_inc_streak = max(max_inc_streak, cur_streak)
                cur_streak = 1

        max_inc_streak = max(max_inc_streak, cur_streak)

        cur_streak = 1
        max_dec_streak = 0
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                cur_streak += 1
            else:
                max_dec_streak = max(max_dec_streak, cur_streak)
                cur_streak = 1

        max_dec_streak = max(max_dec_streak, cur_streak)
        
        return max(max_inc_streak, max_dec_streak)


        