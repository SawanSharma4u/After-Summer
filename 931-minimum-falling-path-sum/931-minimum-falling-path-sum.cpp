class Solution {
    vector<vector<int>> dp;
    int findSum(int i, int j, vector<vector<int>>& matrix){
        if(i==matrix.size()-1 && j >= 0 && j < matrix.size()) return matrix[i][j];
        if(j == matrix.size() || j < 0 || i == matrix.size()) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int temp = min(min(findSum(i+1, j-1, matrix), findSum(i+1, j, matrix)), findSum(i+1, j+1, matrix));
        if(temp!=INT_MAX) temp += matrix[i][j];
        return dp[i][j] = temp;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        dp.resize(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int sum = findSum(0, i, matrix);
            ans = min(sum, ans);
        }
        return ans;
    }
};