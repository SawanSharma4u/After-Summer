class Solution {
    int findParent(int u, vector<int>& parent){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u], parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        for(int i = 1; i <= edges.size(); i++){
            parent[i] = i;
        }
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            u = findParent(u, parent);
            v = findParent(v, parent);
            if(v!=u){
                parent[v] = u;
            }
            else {
                ans = edges[i];
                break;
            }
        }
        return ans;
    }
};