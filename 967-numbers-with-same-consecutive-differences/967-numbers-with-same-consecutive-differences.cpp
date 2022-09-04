class Solution {
    vector<int> ans;
    void solve(int n, int i, int k, int num){
        if(n==0){
            ans.push_back(num);
            return;
        }
        int t = i-k;
        if(t >= 0){
            int temp = num*10 + t;
            solve(n-1, t, k, temp);
        }
        t = i+k;
        if(t < 10 && k!=0){
            int temp = num*10 + t;
            solve(n-1, t, k, temp);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i < 10; i++){
            solve(n-1, i, k, i);
        }
        return ans;
    }
};