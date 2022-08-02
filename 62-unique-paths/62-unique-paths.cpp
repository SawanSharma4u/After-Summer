class Solution {
    // vector<vector<int>> dp;
    // int solve(int m, int n, int i, int j){
    //     if(i==m || j==n){
    //         return 0;
    //     }
    //     if(i==m-1 && j == n-1){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     return dp[i][j] = solve(m, n, i+1, j) + solve(m, n, i, j+1);
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};