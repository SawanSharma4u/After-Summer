class Solution {
    int solve(vector<vector<bool>>& vis, int n, int m, vector<vector<int>>& grid, int i, int j, int obs, int cnt){
        cnt++;
        if(grid[i][j]==2 && cnt+obs==n*m) return 1;
        vis[i][j] = true;
        int ans = 0;
        if(j+1 < m && !vis[i][j+1] && grid[i][j+1]!=-1) ans += solve(vis, n, m, grid, i, j+1, obs, cnt);
        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j]!=-1) ans += solve(vis, n, m, grid, i-1, j, obs, cnt);
        if(i+1 < n && !vis[i+1][j] && grid[i+1][j]!=-1) ans += solve(vis, n, m, grid, i+1, j, obs, cnt);
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1]!=-1) ans += solve(vis, n, m, grid, i, j-1, obs, cnt);
        vis[i][j] = false;
        return ans;
    } 
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==-1){
                    cnt++;
                }
            }
        }
        // cout<<cnt<<" ";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1){
                    ans = solve(vis, n, m, grid, i, j, cnt, 0);
                    break;
                }
            }
        }
        return ans;
    }
};