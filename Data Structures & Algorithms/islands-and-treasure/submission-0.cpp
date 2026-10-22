class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(grid, i, j, 0);
                }
            }
        }
        return;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int cur_dist)
    {
        grid[row][col] = cur_dist;
        cur_dist++;
        if (row > 0 && cur_dist <= grid[row - 1][col])
        {
            dfs(grid, row - 1, col, cur_dist);
        }
        if (col > 0 && cur_dist <= grid[row][col - 1])
        {
            dfs(grid, row, col - 1, cur_dist);
        }
        if (row < grid.size() - 1 && cur_dist <= grid[row + 1][col])
        {
            dfs(grid, row + 1, col, cur_dist);
        }
        if (col < grid[0].size() - 1 && cur_dist <= grid[row][col + 1])
        {
            dfs(grid, row, col + 1, cur_dist);
        }
        return;
    }

};
