class Solution {
    void makeset(vector<int>& parent, vector<int>& rank, int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int u, vector<int>& parent){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = findParent(parent[u], parent);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent, rank, n);
        int grp = n;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j]){
                    int u = findParent(i, parent);
                    int v = findParent(j, parent);
                    if(u!=v){
                        parent[u] = v;
                        grp--;
                    }
                }
            }
        }
        return grp;
    }
};