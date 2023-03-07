class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    checkAdjecent(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void checkAdjecent(vector<vector<char>> &grid, int i, int j)
    {
        // out of bound check
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return;
        }
        if (grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';
        checkAdjecent(grid, i + 1, j);
        checkAdjecent(grid, i - 1, j);
        checkAdjecent(grid, i, j + 1);
        checkAdjecent(grid, i, j - 1);
    }
};