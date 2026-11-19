class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int sub_size = (matrix.size() + 1) / 2;

        for (int i = 0; i < sub_size; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                rotate_nums(matrix, i, j, n);

            }
        }
        return;
        
    }
    void rotate_nums(vector<vector<int>>& matrix, int x, int y, int n)
    {

        int old_val = matrix[x][y];

        for (int i = 0; i < 4; i++)
        {
            int new_x = y;
            int new_y = n - 1 - x;

            int temp = matrix[new_x][new_y];

            matrix[new_x][new_y] = old_val;

            old_val = temp;

            x = new_x;
            y = new_y;
        } 
    }
};
