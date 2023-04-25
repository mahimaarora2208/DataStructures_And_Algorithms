#include <set>
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int row = 0; row < grid.size(); row++){
           for (int col = 0; col < grid[0].size(); col++){
            if(grid[row][col] == 1){
                max_area = max(max_area, sum_islands(grid, row, col));       
            }
        }  
    }
        return max_area;
    }
    int sum_islands(vector<vector<int>>& grid, int row, int col)  {
    // boundary condition
    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
        return 0;
    }
    
    if (grid[row][col]!= 1){
        return 0;
    }
    grid[row][col] = 2;
    return (1 + sum_islands(grid, row+1, col) + sum_islands(grid, row-1, col)+
    sum_islands(grid, row, col+1)+ sum_islands(grid, row, col-1));
    }
};