class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size());
        int ans = 0;
        for(int i = matrix.size()-1; i >= 0; i--){
            int last;
            for(int j = matrix[0].size()-1; j >= 0; j--){
                if(i==matrix.size()-1){
                    dp[j] = matrix[i][j]-'0';
                    ans = max(ans, dp[j]);
                }
                else if(j == matrix[0].size()-1){
                    last = matrix[i][j]-'0';
                    ans = max(ans, last);
                }
                else{
                    if(matrix[i][j]-'0'){
                        int temp = last;
                        last = 1 + min(dp[j], min(dp[j+1], last));
                        dp[j+1] = temp;
                        ans = max(last, ans);
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
        return ans*ans;
    }
};