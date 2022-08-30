class Solution {
    vector<int> find(vector<vector<int>> r, int k){
        unordered_map<int, list<int>> adj;
        int n = r.size();
        vector<int> indegree(k+1, 0);
        for(int i = 0; i < n; i++){
            int u = r[i][0];
            int v = r[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 1; i <= k; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neb: adj[node]){
                indegree[neb]--;
                if(indegree[neb]==0){
                    q.push(neb);
                }
            }
        }
        return ans;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        //Find Topological sort or both mat;
        vector<int> row = find(rowConditions, k);
        vector<vector<int>> res;
        if(row.size()!=k) return res;
        vector<int> col = find(colConditions, k);
        if(col.size()!=k) return res;
        res.resize(k, vector<int>(k));
        vector<int> idx(k+1,0);
        for(int j=0;j<col.size();j++){
            idx[col[j]] = j;
        }
        for(int i=0;i<k;i++){
            res[i][idx[row[i]]] = row[i];
        }
        return res;
    }
};