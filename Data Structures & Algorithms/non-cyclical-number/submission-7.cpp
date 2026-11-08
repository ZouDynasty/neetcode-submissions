class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_map<int, bool> visited;

        int cur = n;

        while(cur != 1)
        {
            if (visited[cur] == true)
            {
                return false;
            }
            visited[cur] = true;

            int sum = 0;

            for (int i = 0; i <= floor(log10(cur)); i++)
            {
                sum = sum + int(pow(cur / int(pow(10, i)) % 10, 2));
            }

            cur = sum;

        }
        return true;
        
    }
};
