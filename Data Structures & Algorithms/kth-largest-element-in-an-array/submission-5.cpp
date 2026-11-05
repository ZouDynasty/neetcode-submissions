class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, less<int>> p;

        for(int i = 0; i < nums.size(); i++)
        {
            p.push(nums[i]);
        }

        for(int i = nums.size() - 1; i > nums.size() - k; i--)
        {
            int largest = p.top();
            p.pop();
        }

        return p.top();
    }
};
