class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<int> dp(matrix[0].size());
        int ans = 0;
        for(int i = matrix.size()-1; i >= 0; i--){
            int last;
            for(int j = matrix[0].size()-1; j >= 0; j--){
                if(i==matrix.size()-1){
                    dp[j] = matrix[i][j];
                    ans += dp[j];
                }
                else if(j == matrix[0].size()-1){
                    last = matrix[i][j];
                    ans += last;
                }
                else{
                    if(matrix[i][j]){
                        int temp = last;
                        last = 1 + min(dp[j], min(dp[j+1], last));
                        dp[j+1] = temp;
                        ans += 1 + last-1;
                    }
                    else{
                        dp[j+1]= last;
                        last = 0;
                    }
                    if(j==0){
                        dp[0] = last;
                    }
                }
            }
        }
        return ans;
    }
};