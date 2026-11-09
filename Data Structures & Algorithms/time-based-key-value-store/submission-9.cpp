class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> data;

    TimeMap() 
    {
    }
    
    void set(string key, string value, int timestamp) 
    {
        pair<int, string> item = {timestamp, value};
        this->data[key].push_back(item);
    }
    
    string get(string key, int timestamp) 
    {
        const vector<pair<int, string>>& keyResults = this->data[key];

        if (keyResults.size() == 0)
        {
            return "";
        }

        int left = 0;
        int right = keyResults.size() - 1;

        if (timestamp < keyResults[left].first)
        {
            return "";
        }
        if (timestamp > keyResults[right].first)
        {
            return keyResults[right].second;
        }

        int middle = (left + right) / 2 ;

        while (right - 1 > left)
        {
            if (timestamp < keyResults[middle].first)
            {
                right = middle;
                middle = left + (right - left) / 2;
            }
            else if (timestamp > keyResults[middle].first)
            {
                left = middle;
                middle = left + (right - left) / 2;
            }
            else
            {
                return keyResults[middle].second;
            }
        }
        if (timestamp == keyResults[right].first)
        {
            return keyResults[right].second;
        }
        return keyResults[left].second;

    }
};
