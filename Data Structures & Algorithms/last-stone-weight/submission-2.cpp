class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int, vector<int>, less<int>> minHeap;
        
        for (int stone: stones)
        {
            minHeap.push(stone);
        }

        while(minHeap.size() > 1)
        {   
            int last = minHeap.top();
            minHeap.pop();
            int secondLast = minHeap.top();
            minHeap.pop();

            if (secondLast != last)
            {
                minHeap.push(abs(last - secondLast));
            }            
        }

        if (minHeap.size() == 1)
        {
            return minHeap.top();
        }

        return {};

        
    }
};
