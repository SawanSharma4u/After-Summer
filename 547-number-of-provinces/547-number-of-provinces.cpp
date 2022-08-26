class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int cnt = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                cnt++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    visited[node] = true;
                    for(int j = 0; j < isConnected.size(); j++){
                        if(!visited[j] && isConnected[node][j]==1){
                            q.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};