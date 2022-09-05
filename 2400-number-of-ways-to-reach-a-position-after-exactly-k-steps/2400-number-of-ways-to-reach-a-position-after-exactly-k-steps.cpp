class Solution {
    int solve(int i, int j, int k, vector<vector<int>>& dp){
        if(k==0){
            if(i==j) return 1;
            return 0;
        }
        if(dp[1001+i][k]!=-1) return dp[1001+i][k];
        int a = solve(i+1, j, k-1, dp);
        int b = solve(i-1, j, k-1, dp);
        return dp[1001+i][k] = (a + b)%1000000007;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001, vector<int> (k+1,-1));
        return solve(startPos, endPos, k, dp);
    }
};