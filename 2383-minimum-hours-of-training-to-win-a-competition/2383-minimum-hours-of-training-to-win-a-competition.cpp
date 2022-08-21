class Solution {
public:
    int minNumberOfHours(int ie, int ix, vector<int>& e, vector<int>& x) {
        int n = e.size();
        int cnte = 0, cntx = 0;
        for(int i = 0; i < n; i++){
            cnte += e[i];
            while(ix+cntx <= x[i]){
                cntx++;
            }
            ix += x[i];
        }
        if(cnte >= ie){
            return cnte-ie+1 + cntx;
        }
        return cntx;
    }
};