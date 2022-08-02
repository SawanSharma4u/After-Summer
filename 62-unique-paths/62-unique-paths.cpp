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
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j==0) dp[j] = dp[j];
                else dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};