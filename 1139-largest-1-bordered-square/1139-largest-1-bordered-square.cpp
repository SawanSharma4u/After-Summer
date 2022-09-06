class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp1(n, vector<int>(m));
        vector<vector<int>> dp2(n, vector<int>(m));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j==0){
                    dp1[i][j] = matrix[i][j];
                }
                else if(matrix[i][j]==1){
                    dp1[i][j] = dp1[i][j-1]+1;
                }
                else{
                    dp1[i][j] = 0;
                }
                if(i==0){
                    dp2[i][j] = matrix[i][j];
                }
                else if(matrix[i][j]==1){
                    dp2[i][j] = dp2[i-1][j]+1;
                }
                else{
                    dp2[i][j] = 0;
                }
                
                int temp = min(dp1[i][j], dp2[i][j]);
                // cout<<i-temp+1<<" "<<j-temp+1<<endl;
                for(int k = temp; k > ans; k--){
                    if(dp1[i-k+1][j] >= k && dp2[i][j-k+1] >= k){
                        ans = max(ans, k);
                    }
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout<<dp2[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans*ans;
    }
};