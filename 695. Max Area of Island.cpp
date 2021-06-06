class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0||y<0||x>=grid[0].size()||y>=grid.size()||grid[y][x]==0) return 0;
        
        grid[y][x] = 0;
        return (1+dfs(grid, x+1, y)
               +dfs(grid, x-1, y)
               +dfs(grid, x, y+1)
               +dfs(grid, x, y-1));
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int _max=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    _max = max(_max, dfs(grid, j, i));
                }                
            }
        }
        
        return _max;
    }
};