class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {   
        vector<int> positive(nums.size(), 0);
        vector<int> negative(nums.size(), 0);

        if (nums.size() == 1)
        {
            return nums[0];
        }

        if (nums[0] > 0)
        {
            positive[0] = nums[0];
            negative[0] = nums[0];
        }
        else if (nums[0] < 0)
        {
            negative[0] = nums[0];
            positive[0] = nums[0];
        }

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                positive[i] = max(nums[i], nums[i] * positive[i - 1]);
                negative[i] = nums[i] * negative[i - 1];
            }
            else if (nums[i] < 0)
            {
                negative[i] = min(nums[i], nums[i] * positive[i - 1]);
                positive[i] = nums[i] * negative[i - 1];
            }
            if (nums[i] == 0)
            {
                positive[i] = 0;
                negative[i] = 0;
            }
        }

        int max_product = 0;
        for (int i = 0; i < positive.size(); i++)
        {
            max_product = max(max_product, positive[i]);
        }

        return max_product;

    }
};
