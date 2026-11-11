class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slowIndex = 0;
        int fastIndex = 0;

        // slow and fast meeting means we find a cycle
        while(slowIndex < nums.size())
        {
            slowIndex = nums[slowIndex];
            fastIndex = nums[nums[fastIndex]];
            if (slowIndex == fastIndex)
            {
                slowIndex = 0;
                while (slowIndex != fastIndex)
                {
                    fastIndex = nums[fastIndex];
                    slowIndex = nums[slowIndex];
                }

                return slowIndex;
            }
        }
    }
};
