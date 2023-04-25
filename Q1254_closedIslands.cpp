#include <iostream>
#include <vector>
using namespace std;

/*
[[0,0,1,1,0,1,0,0,1,0],
 [1,1,0,1,1,0,1,1,1,0],
 [1,0,1,1,1,0,0,1,1,0],
 [0,1,1,0,0,0,0,1,0,1],
 [0,0,0,0,0,0,1,1,1,0],
 [0,1,0,1,0,1,0,1,1,1],
 [1,0,1,0,1,1,0,0,0,1],
 [1,1,1,1,1,1,0,0,0,0],
 [1,1,1,0,0,1,0,1,0,1],
 [1,1,1,0,1,1,0,1,1,0]]
*/
void dfs(vector<vector<int>>& grid, int row, int col)  {
    // boundary condition
    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
        return;
    }
    
    if (grid[row][col] == 1){
        return;
    }
    grid[row][col] = 1;
    dfs(grid, row+1, col);
    dfs(grid, row-1, col);
    dfs(grid, row, col+1);
    dfs(grid, row, col-1);
}

int closedIsland(vector<vector<int>>& grid) {
     int result = 0;
        for (int row = 0; row < grid.size(); row++){
           for (int col = 0; col < grid[0].size(); col++){
            if(row*col == 0 || row == grid.size()-1 || col == grid[0].size()-1)         { 
                dfs(grid, row, col);
            }
        }  
       }
        for (int row = 0; row < grid.size(); row++){
           for (int col = 0; col < grid[0].size(); col++){
            if(grid[row][col] == 0)         { 
                dfs(grid, row, col);
                result++;
            }
        }  
       }
        return result; 
}


int main(){
   vector<vector<int>> grid{{0,0,1,1,0,1,0,0,1,0},
 {1,1,0,1,1,0,1,1,1,0},
 {1,0,1,1,1,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,0,1},
 {0,0,0,0,0,0,1,1,1,0},
 {0,1,0,1,0,1,0,1,1,1},
 {1,0,1,0,1,1,0,0,0,1},
 {1,1,1,1,1,1,0,0,0,0},
 {1,1,1,0,0,1,0,1,0,1},
 {1,1,1,0,1,1,0,1,1,0}};
 closedIsland(grid);

}