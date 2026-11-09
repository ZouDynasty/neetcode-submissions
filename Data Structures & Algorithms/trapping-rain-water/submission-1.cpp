class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if (n < 3) return 0;

        vector<int> left_vec(n), right_vec(n);

        int left_max = height[0];
        left_vec[0] = height[0];
        
        for (int i = 1; i < n; i++)
        {
            left_vec[i] = max(left_vec[i - 1], height[i]);
        }

        right_vec[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right_vec[i] = max(right_vec[i + 1], height[i]);
        }

        int water = 0;

        for (int i = 0; i < height.size(); i++)
        {
            int min_edge = min(left_vec[i], right_vec[i]);
            water = water + max(0, min_edge - height[i]);
        }

        return water;
        
    }
};