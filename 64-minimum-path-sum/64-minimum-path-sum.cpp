class Solution {
public:
    int minPathSum(vector<vector<int>>& dp) {
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[0].size(); j++){
                if(i==0 && j!=0){
                    dp[i][j] += dp[i][j-1];
                }
                else if(i > 0){
                    if(j==0) dp[i][j] += dp[i-1][j];
                    else{
                        dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};