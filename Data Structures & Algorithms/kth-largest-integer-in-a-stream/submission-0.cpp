class KthLargest {
public:
    vector<int> stream;
    int k;
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        stream = nums;
    }
    
    int add(int val) 
    {
        stream.push_back(val);

        sort(stream.begin(), stream.end());

        return stream[stream.size() - k];
    }
};
