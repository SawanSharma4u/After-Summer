class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int m = 9;
        for(int i = 0; i < n; i++){
            vector<bool> mp(10);
            for(int j =0; j < m; j++){
                if(board[i][j]=='.') continue;
                if(mp[board[i][j]-'0']==true) return false;
                else{
                    mp[board[i][j]-'0'] = true;
                }
            }
        }
        for(int i = 0; i < m; i++){
            vector<bool> mp(10);
            for(int j =0; j < n; j++){
                if(board[j][i]=='.') continue;
                if(mp[board[j][i]-'0']==true) return false;
                else{
                    mp[board[j][i]-'0'] = true;
                }
            }
        }
        for(int i = 0; i < n; i=i+3){
            for(int j =0; j < m; j=j+3){
                vector<bool> mp(10);
                for(int k = i; k < i+3; k++){
                    for(int m = j; m < j+3; m++){
                        if(board[k][m]=='.') continue;
                        if(mp[board[k][m]-'0']==true) return false;
                        else{
                            mp[board[k][m]-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};