class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int minSize = 0;

    priority_queue<int, vector<int>, less<int>> maxHeap; 
    int maxSize = 0;

    // 1 -> 10 maxHeap
    // 20 -> 10 minHeap

    MedianFinder() 
    {
    }
    
    void addNum(int num) 
    {
        if (minSize == 0 && maxSize == 0)
        {
            minHeap.push(num);
            minSize++;
            return;
        }
        if (minSize == 0 && maxSize == 1)
        {
            if (num < maxHeap.top())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);
                minSize++;
            }
            else
            {
                minHeap.push(num);
                minSize++;
            }
            return;
        }

        if (maxSize == 0)
        {
            if (num > minHeap.top())
            {
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
                maxSize++;
                return;
            }
        }

        if (num > minHeap.top())
        {
            minHeap.push(num);
            minSize++;
            if (minSize > maxSize + 1)
            {
                int temp = minHeap.top();
                minHeap.pop();
                minSize--;
                maxHeap.push(temp);
                maxSize++;
            }
            return;
        }
        if (num <= minHeap.top())
        {
            maxHeap.push(num);
            maxSize++;
            if (maxSize > minSize + 1)
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxSize--;
                minHeap.push(temp);
                minSize++;
            }
            return;
        }
        return;
    }
    
    double findMedian() 
    {
        if (minSize == 1 && maxSize == 0)
        {
            return minHeap.top();
        }
        if (maxSize == 1 && minSize == 0)
        {
            return maxHeap.top();
        }
        if (maxSize < minSize)
        {
            return minHeap.top();
        }
        if (minSize < maxSize)
        {
            return maxHeap.top();
        }
        if (maxSize == minSize)
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};
