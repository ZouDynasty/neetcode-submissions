class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;

        int max_volume = 0;

        while (left < right)
        {
            int volume = min(height[left], height[right]) * (right - left);
            
            if (volume > max_volume)
            {
                max_volume = volume;
            }
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_volume;
    }
};