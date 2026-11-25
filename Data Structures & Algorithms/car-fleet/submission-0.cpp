class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int, double>> cars;

        for (int i = 0; i < position.size(); i++)
        {
            double time = (double) (target - position[i]) / speed[i]; 
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b)
        {
            return a.first > b.first;
        });

        int numfleets = 1;
        double cur_time = cars[0].second;

        for (int i = 1; i < cars.size(); i++)
        {
            if (cars[i].second > cur_time)
            {
                cur_time = cars[i].second;
                numfleets++;
            }

        }
        return numfleets;
        
    }
};