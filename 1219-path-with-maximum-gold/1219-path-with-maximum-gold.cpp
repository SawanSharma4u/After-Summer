class Solution {
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j]==0) return 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        int ans = max(max(solve(grid, i-1, j), solve(grid, i, j+1)), max(solve(grid, i+1, j), solve(grid, i, j-1)));
        grid[i][j] = temp;
        return temp + ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    int temp = solve(grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};