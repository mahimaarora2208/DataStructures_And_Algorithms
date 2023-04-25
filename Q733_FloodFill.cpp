class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init_color = image[sr][sc];
        if (init_color == color){
            return image;
        }
        dfs(image, init_color, color, sr,sc);  
        return image;     
    }

    void dfs(vector<vector<int>>& img,int old_color ,int new_color, int row, int col){
        //boundary conditions
        if(row >= img.size() || col >= img[0].size() || row < 0 || col<0){
        return;}

        if (img[row][col] != old_color){
            return;
        }
        img[row][col] = new_color;
        dfs(img, old_color, new_color,row-1, col );
        dfs(img, old_color, new_color,row+1, col );
        dfs(img, old_color, new_color,row, col-1 );
        dfs(img, old_color, new_color,row, col+1 );}
   
};