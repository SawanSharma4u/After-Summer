class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        int ans = 0;
        for(int i = matrix.size()-1; i >= 0; i--){
            for(int j = matrix[0].size()-1; j >= 0; j--){
                if(i==matrix.size()-1 || j == matrix[0].size()-1){
                    dp[i][j] = matrix[i][j]-'0';
                    ans = max(ans, dp[i][j]);
                }
                else{
                    if(matrix[i][j]-'0'){
                        dp[i][j] = 1 + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
                        ans = max(dp[i][j], ans);
                    }
                    else dp[i][j]= 0;
                }
            }
        }
        return ans*ans;
    }
};